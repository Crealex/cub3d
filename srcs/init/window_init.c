/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/10 16:41:45 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	refresh_window(t_data *data)
{
	t_player	*player;
	
	player = data->player;
	compute_square(data, player);
	mlx_put_image_to_window(data->mlx, data->window, data->background, \
		0, 0);
	mlx_put_image_to_window(data->mlx, data->window, data->mapi->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->window, player->img,\
		player->posx - player->half, player->posy - player->half);
	dup_square(data);
}

t_data	*data_init(t_map *mapi)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->winsize_x = 4000;
	data->winsize_y = 1600;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->winsize_x, data->winsize_y, \
		"dont mind me im just a square");
	data->tilesize = 100;
	mapi->len_x = 13 * data->tilesize;
	mapi->len_y = 7 * data->tilesize;
	mapi->img = mlx_new_image(data->mlx, mapi->len_x, mapi->len_y);
	data->mapi = mapi;
	bg_init(data, mapi);
	data->player = square_init(data);
	return (data);
}
