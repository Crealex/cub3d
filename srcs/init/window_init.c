/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/27 16:27:53 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	dup_square(t_data *data)
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
}

void	refresh_window(t_data *data)
{
	t_player	*player;
	
	player = data->player;
	compute_square(player);
	mlx_put_image_to_window(data->mlx, data->window, data->background, \
		0, 0);
	mlx_put_image_to_window(data->mlx, data->window, player->img,\
		player->posx - player->half, player->posy - player->half);
	dup_square(data);
}

void	clear_square(t_player *square)
{
	int	i;
	int	j;
	int	half_tile;

	half_tile = square->tile / 2;
	i = - half_tile;
	while (i <=  half_tile)
	{
		j = - half_tile;
		while (j <=  half_tile)
		{
			*(unsigned int *)(square->addr + ((j +  half_tile) * \
				(square->bpp / 8)) + ((i +  half_tile) * \
				square->line_size)) = 0x000000;
			j++;
		}
		i++;
	}
}

void	fill_square(t_player *square, int rx, int ry)
{
	int	offset;

	offset = (rx * (square->bpp / 8)) + (ry * square->line_size);
	*(unsigned int *)(square->addr + offset) = square->colour;
}
			
void	compute_square(t_player *square)
{
	int		x;
	int		y;
	int		rx;
	int		ry;

	square->addr = mlx_get_data_addr(square->img, &square->bpp, \
			&square->line_size, &square->endian);
	clear_square(square);
	y = -square->half;
	while (y < square->half)
	{
		x = -square->half;
		while (x < square->half)
		{
			rx = (int)(square->cos_a * x - square->sin_a * y) + square->tile / 2;
			ry = (int)(square->sin_a * x + square->cos_a * y) + square->tile / 2;
			if (rx >= 0 && rx < square->tile && ry >= 0 && ry < square->tile)
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
	square->colour = 0xFF0000;
	square->tile = 500;
	square->side = (int)(square->tile / sqrt(2));
	square->half = square->side / 2;
	square->a = 0;
	square->w = 0;
	square->s = 0;
	square->d = 0;
	square->left = 0;
	square->right = 0;
	square->img = mlx_new_image(data->mlx, square->tile, square->tile);
	square->posx = 500;
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
