/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:08:00 by alexandre         #+#    #+#             */
/*   Updated: 2025/07/12 19:16:04 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_img	*display_anim_open(t_data *data)
{
	if (data->map->timer < 10000000)
		return (data->textures->door_1);
	else if (data->map->timer < 20000000)
		return (data->textures->door_2);
	else if (data->map->timer < 30000000)
		return (data->textures->door_3);
	else if (data->map->timer < 40000000)
		return (data->textures->door_4);
	else if (data->map->timer < 50000000)
		return (data->textures->door_5);
	else if (data->map->timer < 60000000)
		return (data->textures->door_6);
	else if (data->map->timer < 70000000)
		return (data->textures->door_7);
	else if (data->map->timer < 80000000)
		return (data->textures->door_8);
	else if (data->map->timer < 90000000)
		return (data->textures->door_9);
	else
	{
		data->map->matrix[data->player->sy][data->player->sx] = 'O';
		return (data->textures->door_10);
	}
}

t_img	*display_anim_close(t_data *data)
{
	if (data->map->timer < 10000000)
		return (data->textures->door_10);
	else if (data->map->timer < 20000000)
		return (data->textures->door_9);
	else if (data->map->timer < 30000000)
		return (data->textures->door_8);
	else if (data->map->timer < 40000000)
		return (data->textures->door_7);
	else if (data->map->timer < 50000000)
		return (data->textures->door_6);
	else if (data->map->timer < 60000000)
		return (data->textures->door_5);
	else if (data->map->timer < 70000000)
		return (data->textures->door_4);
	else if (data->map->timer < 80000000)
		return (data->textures->door_3);
	else if (data->map->timer < 90000000)
		return (data->textures->door_2);
	else
		return (data->textures->door_1);
}

void	anim_door(t_data *data, t_hit hit, int x)
{
	double			door_size;
	t_img			*door_tex;
	int				j;
	unsigned int	door_pix;

	door_size = find_wall_size(data, hit.door_hit->dist);
	hit.door_hit->wall_size = door_size;
	door_tex = define_tex(*hit.door_hit, data);
	if (door_tex == NULL || !door_tex->addr)
		return ;
	hit.door_hit->tex_x = define_tex_x(*hit.door_hit, door_tex);
	j = -door_size / 2;
	if (j < -data->winsize_y / 2)
		j = -data->winsize_y / 2;
	while (j < door_size / 2 && j < data->winsize_y / 2)
	{
		hit.door_hit->i = j;
		door_pix = define_pix_texture(*hit.door_hit, data, door_tex);
		if (door_pix != 0xff000000)
			put_pixel(data, x, data->winsize_y / 2 + j, door_pix);
		j++;
	}
}

void	handle_timer(t_data *data)
{
	if (data->map->door_anim == 1 || data->map->door_anim == 2)
		data->map->timer += 1;
	if (data->map->timer > 100000000)
	{
		data->map->door_anim = 0;
		data->map->timer = 0;
	}
}
