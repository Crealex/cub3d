/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:39:36 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/13 14:58:40 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	define_step(double n)
{
	if (n < 0)
		return (-1);
	return (1);
}

double	define_side_dist(t_dda data, char c, t_player player)
{
	if (c == 'x')
	{
		if (data.ray_dirx < 0)
			return ((player.posx - data.mapx) * data.delta_distx);
		return ((data.mapx + 1.0 - player.posx) * data.delta_distx);
	}
	else if (c == 'y')
	{
		if (data.ray_diry < 0)
			return ((player.posy - data.mapy) * data.delta_disty);
		return ((data.mapy + 1.0 - player.posy) * data.delta_disty);
	}
	return (0);
}

void	perform_dda(t_dda *data, t_map *map)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->side_distx < data->side_disty)
		{
			data->side_distx += data->delta_distx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->side_disty += data->delta_disty;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (map->matrix[data->mapy][data->mapx] == '1')
			data->hit = 1;
	}
}

double	ray_cast(t_player *player, t_map *map)
{
	t_dda	data;

	data.ray_dirx = cos(player->angle);
	data.ray_diry = sin(player->angle);
	if (data.ray_dirx == 0)
		data.delta_distx = 1e30;
	else
		data.delta_distx = ft_abs(1.0 / data.ray_dirx);
	if (data.ray_diry == 0)
		data.delta_disty = 1e30;
	else
		data.delta_disty = ft_abs(1.0 / data.ray_diry);
	data.mapx = (int)player->posx;
	data.mapy = (int)player->posy;
	data.stepx = define_step(data.ray_dirx);
	data.stepy = define_step(data.ray_diry);
	data.side_distx = define_side_dist(data, 'x', *player);
	data.side_disty = define_side_dist(data, 'y', *player);
	perform_dda(&data, map);
	if (data.side == 0)
		data.perp_wall_dist = (data.side_distx - data.delta_distx);
	else
		data.perp_wall_dist = (data.side_disty - data.delta_disty);
	return (data.perp_wall_dist);
}
