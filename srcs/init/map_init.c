/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:26:32 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/17 11:59:28 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_empty(char c)
{
	if (c == '0' || c == 'E' || c == 'O' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

void	colour_map(t_data *data, t_minimap *mapi, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->tilesize)
	{
		j = 0;
		while (j < data->tilesize)
		{
			if (mapi->map[y][x] == '1')
				*(int *)(mapi->addr + ((x * data->tilesize + j) * \
				(mapi->bpp / 8)) + ((y * data->tilesize + i) * \
				mapi->line_size)) = 0x0000FF;
			else if (is_empty(mapi->map[y][x]))
				*(int *)(mapi->addr + ((x * data->tilesize + j) * \
				(mapi->bpp / 8)) + ((y * data->tilesize + i) * \
				mapi->line_size)) = 0xAAAAAA;
			else
				*(int *)(mapi->addr + ((x * data->tilesize + j) * \
				(mapi->bpp / 8)) + ((y * data->tilesize + i) * \
				mapi->line_size)) = 0x000000;			
			j++;
		}
		i++;
	}
}

void	map_init(t_data *data, t_minimap *mapi)
{
	int	i;
	int	j;

	i = 0;
	mapi->addr = mlx_get_data_addr(mapi->img, &mapi->bpp, &mapi->line_size, &mapi->endian);
	while (mapi->map[i])
	{
		j = 0;
		while (mapi->map[i][j])
		{
			colour_map(data, mapi, j, i);
			j++;
		}
		i++;
	}
}

void	find_player_pos(t_data *data, t_player *square, t_minimap *mapi)
{
	int	i;
	int	j;

	i = 0;
	while (mapi->map[i])
	{
		j = 0;
		while (mapi->map[i][j])
		{
			if (mapi->map[i][j] == 'E' || mapi->map[i][j] == 'S' \
			|| mapi->map[i][j] == 'O' || mapi->map[i][j] == 'W')
			{
				square->posx = j * data->tilesize + square->half;
				square->posy = i * data->tilesize + square->half;
			}
			j++;
		}
		i++;
	}
}
