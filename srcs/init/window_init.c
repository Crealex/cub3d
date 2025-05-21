/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 20:28:59 by psoulie          ###   ########.fr       */
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

void	refresh_window(t_data *data)
{
	t_player	*player;

	player = data->player;
	mlx_put_image_to_window(data->mlx, data->window, data->background, \
			0, 0);
	mlx_put_image_to_window(data->mlx, data->window, player->img,\
			player->posx, player->posy);
	if (player->posx < 0 || player->posx + player->side > data->winsize_x
			||player->posy < 0 || player->posy + player->side > data->winsize_y)
			dup_square(data);
	usleep(200);
}

static void	fill_square(t_player *square)
{
	int		i;
	int		j;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;

	addr = mlx_get_data_addr(square->img, &bpp, &line_size, &endian);
	i = 0;
	while (i < square->side)
	{
		j = 0;
		while (j < square->side)
		{
			*(unsigned int *)(addr + i * line_size + j * (bpp / 8)) = square->colour;
			j++;
		}
		i++;
	}
}

static t_player	*square_init(t_data *data)
{
	t_player	*square;

	square = malloc(sizeof(t_player));
	square->angle = 0;
	square->colour =  0xFF0000;
	square->side = 300;
	square->a = 0;
	square->w = 0;
	square->s = 0;
	square->d = 0;
	square->img = mlx_new_image(data->mlx, square->side, square->side);
	square->posx = 600;
	square->posy = 500;
	fill_square(square);
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
