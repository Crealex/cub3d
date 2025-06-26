/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/26 10:22:35 by atomasi          ###   ########.fr       */
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
	mlx_put_image_to_window(data->mlx, data->window, data->mapi->img, data->winsize_x - data->mapi->len_x * data->tilesize, 0);
	mlx_put_image_to_window(data->mlx, data->window, player->img,
		player->posx - player->half + data->winsize_x - data->mapi->len_x * data->tilesize, player->posy - player->half);
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

t_data	*data_init(t_minimap *mapi, t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->winsize_x = 2000;
	data->winsize_y = 1300;
	data->window = mlx_new_window(data->mlx, data->winsize_x, data->winsize_y, \
		"cacaboudin");
	data->tilesize = 25;
	mapi->len_x = tab_width(map->matrix);
	mapi->len_y = tab_size(map->matrix);
	mapi->img = mlx_new_image(data->mlx, mapi->len_x * data->tilesize, mapi->len_y * data->tilesize);
	data->mapi = mapi;
	map_init(data, mapi);
	data->background = background_init(data);
	data->map = map;
	data->player = square_init(data);
	data->textures = textures_init(data);
	return (data);
}
