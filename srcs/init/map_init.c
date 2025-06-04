/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:26:32 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/04 15:38:32 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_map(t_data *data, t_map *mapi, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->tilesize)
	{
		j = 0;
		while (j < data->tilesize)
		{
			if (mapi->map[y][x] == '1' && mapi->map[y + 1])
				*(int *)(mapi->addr + ((x * data->tilesize + j) * (mapi->bpp / 8)) + ((y * data->tilesize + i) * mapi->line_size)) = 0x0000FF;
			// else
			// 	*(int *)(mapi->addr + ((x * data->tilesize + j) * (mapi->bpp / 8)) + ((y * data->tilesize + i) * mapi->line_size)) = 0x000000;
			j++;
		}
		i++;
	}
}

void	bg_init(t_data *data, t_map *mapi)
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
			fill_map(data, mapi, j, i);
			j++;
		}
		i++;
	}
}
