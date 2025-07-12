/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:45:52 by alexandre         #+#    #+#             */
/*   Updated: 2025/07/12 18:56:54 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	hit_door(t_map *map, t_dda *data)
{
	if (map->matrix[data->mapy][data->mapx] == 'O' ||
		map->matrix[data->mapy][data->mapx] == 'C')
	{
		return (1);
	}
	return (0);
}

void	handle_door(t_map *map, t_dda *data, t_hit *hit)
{
	if (map->door_anim && hit->door_hit)
	{
		hit->door_hit->type = map->matrix[data->mapy][data->mapx];
		hit->door_hit->ray_x = data->ray_dirx;
		hit->door_hit->ray_y = data->ray_diry;
		hit->door_hit->side = define_side_hit(data->player->angle
				+ data->offset, data->side);
		if (data->side == 0)
			hit->door_hit->dist = (data->side_distx - data->delta_distx);
		else
			hit->door_hit->dist = (data->side_disty - data->delta_disty);
		hit->door_hit->x = (data->player->posx / TILE_SIZE)
			+ hit->door_hit->dist * data->ray_dirx;
		hit->door_hit->y = (data->player->posy / TILE_SIZE)
			+ hit->door_hit->dist * data->ray_diry;
		hit->door_hit->dist *= cos(data->offset);
	}
	else if (map->matrix[data->mapy][data->mapx] == 'C')
	{
		hit->type = map->matrix[data->mapy][data->mapx];
		data->hit = 1;
	}
}
