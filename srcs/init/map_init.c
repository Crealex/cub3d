/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:26:32 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/03 17:58:50 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_map(int x, int y, t_data *data, t_map *mapi)
{
	char	**map;

	map = mapi->map;
	if (map[(x / data->tilesize)][(y / data->tilesize)] == '0')
		*(unsigned int *)(mapi->addr + (x * (mapi->bpp / 8)) + (y * mapi->line_size)) = 0x000000;
	else
		*(unsigned int *)(mapi->addr + (x * (mapi->bpp / 8)) + (y * mapi->line_size)) = 0xAAAAAA;
}

void	bg_init(t_data *data, t_map *mapi)
{
	int	i;
	int	j;

	i = 0;
	mapi->img  = mlx_new_image(data->mlx, mapi->len_x * data->tilesize, mapi->len_y * data->tilesize);
	mapi->addr = mlx_get_data_addr(mapi->img, &mapi->bpp, &mapi->line_size, &mapi->endian);
	while (i < mapi->len_y)
	{
		j = 0;
		while (j < mapi->len_x)
		{
			fill_map(j, i, data, mapi);
			j++;
		}
		i++;
	}
}
