/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/14 10:53:11 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	refresh_window(t_data *data)
{
	t_player	*player;

	player = data->player;
	compute_square(data, player);
	show_rays(data, player);
	map_init(data, player, data->mapi);
	mlx_put_image_to_window(data->mlx, data->window,
		data->background->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->mapi->img,
		data->winsize_x - MINIMAP_SIZE * data->tilesize, 0);
	mlx_put_image_to_window(data->mlx, data->window, player->img,
		data->winsize_x - (MINIMAP_SIZE / 2 + 1) * data->tilesize,
		(MINIMAP_SIZE / 2) * data->tilesize);
}

t_background	*background_init(t_data *data)
{
	t_background	*bg;

	bg = ft_calloc(sizeof(t_background), 1);
	bg->img = mlx_new_image(data->mlx, data->winsize_x, data->winsize_y);
	bg->addr = mlx_get_data_addr(bg->img, &bg->bpp,
			&bg->line_size, &bg->endian);
	return (bg);
}

t_data	*data_init(t_minimap *mapi, t_map *map)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	data->mlx = mlx_init();
	data->winsize_x = 1920;
	data->winsize_y = 1080;
	data->window = mlx_new_window(data->mlx, data->winsize_x, data->winsize_y,
			"im a full grown cube now (uwu)");
	data->tilesize = 25;
	mapi->len_x = tab_width(map->matrix);
	mapi->len_y = tab_size(map->matrix);
	mapi->img = mlx_new_image(data->mlx, MINIMAP_SIZE * data->tilesize,
			MINIMAP_SIZE * data->tilesize);
	data->mapi = mapi;
	data->background = background_init(data);
	data->map = map;
	data->player = square_init(data);
	map_init(data, data->player, mapi);
	data->textures = textures_init(data);
	return (data);
}
