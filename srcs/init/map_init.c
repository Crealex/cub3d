/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:26:32 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/07 11:58:12 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_empty(char c)
{
	if (c == '0' || c == 'E' || c == 'N' || c == 'W' || c == 'S' || c == 'O')
		return (1);
	return (0);
}

static void	put_colour(t_data *data, t_minimap *mapi, int colour)
{
	(void)data;
	*(int *)(mapi->addr + ((mapi->mx) * \
				(mapi->bpp / 8)) + ((mapi->my) * \
				mapi->line_size)) = colour;
}

static void	colour_map(t_data *data, t_minimap *mapi)
{
			if (mapi->cy < 0 || mapi->cx < 0 || mapi->cy >= mapi->len_y * data->tilesize || mapi->cx > (int)ft_strlen(mapi->map[mapi->cy / data->tilesize]) * data->tilesize)
				put_colour(data, mapi, 0x000000);
			else if (mapi->map[mapi->cy / data->tilesize][mapi->cx / data->tilesize] == '1')
				put_colour(data, mapi, 0x0000FF);
			else if (mapi->map[mapi->cy / data->tilesize][mapi->cx / data->tilesize] == 'C')
				put_colour(data, mapi, 0x12B261);
			else if (is_empty(mapi->map[mapi->cy / data->tilesize][mapi->cx / data->tilesize]))
				put_colour(data, mapi, 0xAAAAAA);
			else
				put_colour(data, mapi, 0x000000);
}

void	map_init(t_data *data, t_player *player, t_minimap *mapi)
{
	mapi->my = 0;
	mapi->cy = (int)(player->posy - player->half) - (MINIMAP_SIZE / 2 * data->tilesize);
	mapi->addr = mlx_get_data_addr(mapi->img, &mapi->bpp, &mapi->line_size, &mapi->endian);
	while (mapi->cy <= (int)(player->posy + player->half) + (MINIMAP_SIZE / 2 * data->tilesize))
	{
		mapi->mx = 0;
		mapi->cx = (int)(player->posx - player->half) - (MINIMAP_SIZE / 2 * data->tilesize);
		while (mapi->cx <= (int)(player->posx + player->half) + (MINIMAP_SIZE / 2 * data->tilesize))
		{
			colour_map(data, mapi);
			mapi->mx++;
			mapi->cx++;
		}
		mapi->my++;
		mapi->cy++;
	}
}

void	find_player_pos(t_data *data, t_player *square, t_map *mapi)
{
	int	i;
	int	j;

	i = 0;
	while (mapi->matrix[i])
	{
		j = 0;
		while (mapi->matrix[i][j])
		{
			if (mapi->matrix[i][j] == 'E' || mapi->matrix[i][j] == 'S' \
			|| mapi->matrix[i][j] == 'N' || mapi->matrix[i][j] == 'W')
			{
				square->posx = j * data->tilesize + square->half;
				square->posy = i * data->tilesize + square->half;
			}
			j++;
		}
		i++;
	}
}
