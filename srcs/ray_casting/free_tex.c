/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:22:29 by alexandre         #+#    #+#             */
/*   Updated: 2025/07/11 11:10:51 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_img(t_img *img, t_data *data)
{
	if (img)
	{
		if (img->path)
			free(img->path);
		if (img->img)
			mlx_destroy_image(data->mlx, img->img);
		free(img);
	}
}

void	free_tex(t_texture *tex, t_data *data)
{
	if (tex)
	{
		free_img(tex->door, data);
		free_img(tex->door_1, data);
		free_img(tex->door_2, data);
		free_img(tex->door_3, data);
		free_img(tex->door_4, data);
		free_img(tex->door_5, data);
		free_img(tex->door_6, data);
		free_img(tex->door_7, data);
		free_img(tex->door_8, data);
		free_img(tex->door_9, data);
		free_img(tex->door_10, data);
		free_img(tex->ea, data);
		free_img(tex->no, data);
		free_img(tex->so, data);
		free_img(tex->we, data);
		free(tex);
	}
}
