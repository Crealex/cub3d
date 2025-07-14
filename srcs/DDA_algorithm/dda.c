/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:39:36 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/14 10:27:45 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	define_side_hit(double angle, int side)
{
	if (side == 0)
	{
		if (cos(angle) > 0)
			return ('W');
		else
			return ('E');
	}
	else
	{
		if (sin(angle) > 0)
			return ('N');
		else
			return ('S');
	}
	return (0);
}

double	define_side_dist(t_dda data, char c, t_player player)
{
	if (c == 'x')
	{
		if (data.ray_dirx < 0)
			return ((player.posx / 25 - data.mapx) * data.delta_distx);
		return ((data.mapx + 1.0 - player.posx / 25) * data.delta_distx);
	}
	else if (c == 'y')
	{
		if (data.ray_diry < 0)
			return ((player.posy / 25 - data.mapy) * data.delta_disty);
		return ((data.mapy + 1.0 - player.posy / 25) * data.delta_disty);
	}
	return (0);
}

static void	perform_dda(t_dda *data, t_map *map, t_hit *hit)
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
		{
			hit->type = map->matrix[data->mapy][data->mapx];
			data->hit = 1;
		}
		if (hit_door(map, data))
			handle_door(map, data, hit);
	}
}

static void	setup_data(t_dda *data, t_player *player)
{
	data->mapx = (int)(player->posx / TILE_SIZE);
	data->mapy = (int)(player->posy / TILE_SIZE);
	data->stepx = define_step(data->ray_dirx);
	data->stepy = define_step(data->ray_diry);
	data->side_distx = define_side_dist(*data, 'x', *player);
	data->side_disty = define_side_dist(*data, 'y', *player);
}

void	ray_cast(t_player *player, t_map *map, double off, t_hit *hit)
{
	t_dda	data;

	fill_data(&data, player, off);
	data.ray_dirx = cos(player->angle + off);
	data.ray_diry = sin(player->angle + off);
	if (data.ray_dirx == 0)
		data.delta_distx = 1e30;
	else
		data.delta_distx = ft_abs(1.0 / data.ray_dirx);
	if (data.ray_diry == 0)
		data.delta_disty = 1e30;
	else
		data.delta_disty = ft_abs(1.0 / data.ray_diry);
	hit->ray_x = data.ray_dirx;
	hit->ray_y = data.ray_diry;
	setup_data(&data, player);
	perform_dda(&data, map, hit);
	hit->side = define_side_hit(player->angle + off, data.side);
	if (data.side == 0)
		hit->dist = (data.side_distx - data.delta_distx);
	else
		hit->dist = (data.side_disty - data.delta_disty);
	hit->x = (player->posx / TILE_SIZE) + hit->dist * data.ray_dirx;
	hit->y = (player->posy / TILE_SIZE) + hit->dist * data.ray_diry;
	hit->dist *= cos(off);
}
