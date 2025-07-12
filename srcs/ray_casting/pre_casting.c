/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:59:53 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/12 18:19:19 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	hit_init(t_hit *hit)
{
	hit->dist = 0;
	hit->i = 0;
	hit->ray_x = 0;
	hit->ray_y = 0;
	hit->side = '.';
	hit->tex_x = 0;
	hit->type = '.';
	hit->wall_size = 0;
	hit->x = 0;
	hit->y = 0;
}

void	draw_ray(t_data *data, t_player *player, double offset, int x)
{
	t_hit	hit;

	ft_memset(&hit, 0, sizeof(t_hit));
	hit_init(&hit);
	hit.door_hit = ft_calloc(sizeof(t_hit), 1);
	data->background->cos_a = cos(player->angle + offset);
	data->background->sin_a = sin(player->angle + offset);
	ray_cast(player, data->map, offset, &hit);
	place_wall(data, hit, x);
	free(hit.door_hit);
}

void	show_rays(t_data *data, t_player *player)
{
	double	offset;
	int		x;

	base_bg(data);
	x = 0;
	while (x < data->winsize_x)
	{
		offset = ((double)x / data->winsize_x) * FOV - FOV / 2;
		draw_ray(data, player, offset, x);
		x++;
	}
}
