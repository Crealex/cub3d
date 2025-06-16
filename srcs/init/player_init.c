/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:07:27 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/16 10:39:22 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* void	dup_square(t_data *data)
{
	t_player	*square;

	square = data->player;
	if (square->posx - square->half < square->half)
	{
		if (square->posx + square->half < 0)
			square->posx += data->winsize_x;
		else
			mlx_put_image_to_window(data->mlx, data->window, square->img, \
				square->posx + data->winsize_x - square->half, square->posy - square->half);
	}
	if (square->posx + square->half > data->winsize_x)
	{
		if (square->posx - square->half > data->winsize_x)
			square->posx -= data->winsize_x;
		else
			mlx_put_image_to_window(data->mlx, data->window, square->img, \
				square->posx - data->winsize_x - square->half, square->posy - square->half);
	}
	if (square->posy - square->half < 0)
	{
		if (square->posy + square->half < 0)
			square->posy += data->winsize_y;
		else
			mlx_put_image_to_window(data->mlx, data->window, square->img, \
				square->posx - square->half, square->posy + data->winsize_y - square->half);
	}
	if (square->posy + square->half > data->winsize_y)
	{
		if (square->posy - square->half > data->winsize_y)
			square->posy -= data->winsize_y;
		else
			mlx_put_image_to_window(data->mlx, data->window, square->img, \
				square->posx - square->half, square->posy - data->winsize_y - square->half);
	}
} */

void	clear_square(t_data *data, t_player *square)
{
	int		i;
	int		j;
	t_minimap	*mapi;

	i = 0;
	mapi = data->mapi;
	while (i <= data->tilesize)
	{
		j = 0;
		while (j <= data->tilesize)
		{
			*(unsigned int *)(square->addr + (j * (square->bpp / 8)) + \
				(i * square->line_size)) = *(unsigned int *)(mapi->addr + \
				((int)square->posx - square->half + j) * (mapi->bpp / 8) + \
				((int)square->posy - square->half + i) * mapi->line_size);
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

	square->addr = mlx_get_data_addr(square->img, &square->bpp, \
			&square->line_size, &square->endian);
	clear_square(data, square);
	y = -square->side / 2;
	while (y < square->side / 2)
	{
		x = -square->side / 2;
		while (x < square->side / 2)
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
			x++; 
		}
		y++;
	}
}

t_player	*square_init(t_data *data)
{
	t_player	*square;

	square = malloc(sizeof(t_player));
	square->angle = 3 * M_PI / 2;
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
	find_player_pos(data, square, data->mapi);
	compute_square(data, square);
	return (square);
}
