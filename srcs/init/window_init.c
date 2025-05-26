/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/26 12:29:04 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	dup_square(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (player->posx < 0)
	{
		if (player->posx + player->side < 0)
			player->posx += data->winsize_x;
		else
			mlx_put_image_to_window(data->mlx, data->window, player->img, \
				player->posx + data->winsize_x, player->posy);
	}
	if (player->posx + player->side > data->winsize_x)
	{
		if (player->posx > data->winsize_x)
			player->posx -= data->winsize_x;
		else
			mlx_put_image_to_window(data->mlx, data->window, player->img, \
				player->posx - data->winsize_x, player->posy);
	}
	if (player->posy < 0)
	{
		if (player->posy + player->side < 0)
			player->posy += data->winsize_y;
		else
			mlx_put_image_to_window(data->mlx, data->window, player->img, \
				player->posx, player->posy + data->winsize_y);
	}
	if (player->posy + player->side > data->winsize_y)
	{
		if (player->posy > data->winsize_y)
			player->posy -= data->winsize_y;
		else
			mlx_put_image_to_window(data->mlx, data->window, player->img, \
				player->posx, player->posy - data->winsize_y);
	}
}

void	fill_square(t_player *square, int rx, int ry)
{
	int	offset;

	offset = (rx * (square->bpp / 8)) + (ry * square->line_size);
	*(unsigned int *)(square->addr + offset) = square->colour;
}

void	refresh_window(t_data *data)
{
	t_player	*player;

	player = data->player;
	compute_square(player);
	mlx_put_image_to_window(data->mlx, data->window, data->background, \
			0, 0);
	mlx_put_image_to_window(data->mlx, data->window, player->img,\
			player->posx, player->posy);
	if (player->posx < 0 || player->posx + player->side > data->winsize_x
			||player->posy < 0 || player->posy + player->side > data->winsize_y)
			dup_square(data);
}

void	compute_square(t_player *square)
{
	int		x;
	int		y;
	int		rx;
	int		ry;

	square->addr = mlx_get_data_addr(square->img, &square->bpp, \
			&square->line_size, &square->endian);
	y = -square->half;
	while (y < square->half)
	{
		x = -square->half;
		while (x < square->half)
		{
			rx = (int)(square->cos_a * x - square->sin_a * y);
			ry = (int)(square->sin_a * x + square->cos_a * y);
			if (rx >= 0 && rx < square->side && ry >= 0 && ry < square->side)
				fill_square(square, rx, ry);
			x++;
		}
		y++;
	}
}

static t_player	*square_init(t_data *data)
{
	t_player	*square;

	square = malloc(sizeof(t_player));
	square->angle = 3 * M_PI / 2;
	square->cos_a = cos(square->angle);
	square->sin_a = sin(square->angle);
	square->colour =  0xFF0000;
	square->side = 300;
	square->half = square->side / 2;
	square->a = 0;
	square->w = 0;
	square->s = 0;
	square->d = 0;
	square->img = mlx_new_image(data->mlx, square->side, square->side);
	square->posx = 600;
	square->posy = 500;
	compute_square(square);
	return (square);
}

t_data	*data_init()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->winsize_x = 2000;
	data->winsize_y = 1600;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->winsize_x, data->winsize_y, \
		"dont mind me im just a square");
	data->background = mlx_new_image(data->mlx, data->winsize_x, data->winsize_y);
	data->player = square_init(data);
	return (data);
}
