/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/11 23:27:17 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	refresh_window(t_data *data)
{
	t_player	*player;
	
	player = data->player;
	compute_square(data, player);
	show_rays(data, player);
	mlx_put_image_to_window(data->mlx, data->window, data->background->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->mapi->img, data->winsize_x - data->mapi->len_x, 0);
	mlx_put_image_to_window(data->mlx, data->window, player->img,
		player->posx - player->half + data->winsize_x - data->mapi->len_x, player->posy - player->half);
	// dup_square(data);
}

t_background	*background_init(t_data *data)
{
	t_background	*bg;

	bg = malloc(sizeof(t_background));
	bg->img = mlx_new_image(data->mlx, data->winsize_x, data->winsize_y);
	bg->addr = mlx_get_data_addr(bg->img, &bg->bpp, &bg->line_size, &bg->endian);
	return (bg);
}

t_data	*data_init(t_map *mapi)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->winsize_x = 1600;
	data->winsize_y = 1000;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->winsize_x, data->winsize_y, \
		"dont mind me im just a square");
	data->tilesize = 25;
	mapi->len_x = 13 * data->tilesize;
	mapi->len_y = 7 * data->tilesize;
	mapi->img = mlx_new_image(data->mlx, mapi->len_x, mapi->len_y);
	data->mapi = mapi;
	map_init(data, mapi);
	data->background = background_init(data);
	data->player = square_init(data);
	return (data);
}
