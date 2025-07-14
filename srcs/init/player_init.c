/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:07:27 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/14 11:03:01 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	clear_square(t_data *data, t_player *square)
{
	int			i;
	int			j;
	t_minimap	*mapi;

	i = 0;
	mapi = data->mapi;
	while (i <= data->tilesize)
	{
		j = 0;
		while (j <= data->tilesize)
		{
			*(unsigned int *)(square->addr + (j * (square->bpp / 8))
					+ (i * square->line_size)) = *(unsigned int *)(mapi->addr
					+ ((int)3 * data->tilesize + j) * (mapi->bpp / 8)
					+ ((int)3 * data->tilesize + i) * mapi->line_size);
			j++;
		}
		i++;
	}
}

static void	fill_square(t_player *square, int rx, int ry, int colour)
{
	int	offset;

	offset = (rx * (square->bpp / 8)) + (ry * square->line_size);
	*(unsigned int *)(square->addr + offset) = colour;
}

void	compute_square(t_data *data, t_player *square)
{
	int		x;
	int		y;
	int		rx;
	int		ry;

	square->addr = mlx_get_data_addr(square->img, &square->bpp,
			&square->line_size, &square->endian);
	clear_square(data, square);
	y = -square->side / 2;
	while (y++ < square->side / 2)
	{
		x = -square->side / 2;
		while (x++ < square->side / 2)
		{
			rx = (int)(square->cos_a * x - square->sin_a * y) + square->half;
			ry = (int)(square->sin_a * x + square->cos_a * y) + square->half;
			if (rx >= 0 && rx < square->tile && ry >= 0 && ry < square->tile)
			{
				if (-1 <= y && y <= 1 && x >= 0)
					fill_square(square, rx, ry, 0x000000);
				else
					fill_square(square, rx, ry, square->colour);
			}
		}
	}
}

t_player	*square_init(t_data *data)
{
	t_player	*square;

	square = ft_calloc(sizeof(t_player), 1);
	square->angle = data->map->player_start * M_PI / 2;
	square->cos_a = cos(square->angle);
	square->sin_a = sin(square->angle);
	square->colour = 0xFF0000;
	square->tile = data->tilesize;
	square->side = (int)(square->tile / sqrt(2));
	square->half = square->tile / 2;
	square->a = 0;
	square->w = 0;
	square->s = 0;
	square->d = 0;
	square->left = 0;
	square->right = 0;
	square->img = mlx_new_image(data->mlx, square->tile, square->tile);
	find_player_pos(data, square, data->map);
	return (square);
}
