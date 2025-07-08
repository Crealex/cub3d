/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:59:53 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/08 13:00:17 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_ray(t_data *data, t_player *player, double offset, int x)
{
	t_hit	hit;

	data->background->cos_a = cos(player->angle + offset);
	data->background->sin_a = sin(player->angle + offset);
	ray_cast(player, data->map, offset, &hit);
	place_wall(data, hit, offset, x);
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
