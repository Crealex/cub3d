/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:59:53 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/11 23:30:04 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	find_wall(t_data *data, t_player *player, double test, double cos_a, double sin_a)
{
	char	**map;

	map = data->mapi->map;
	if (map[(int)((player->posy + sin_a * test) / data->tilesize)][(int)((player->posx + cos_a * test) / data->tilesize)] == '1')
		return (1);
	return (0);
}

void	draw_ray(t_data *data, t_player *player, double offset, double iter)
{
	double	cos_a;
	double	sin_a;
	double	i;

	cos_a = cos(player->angle + offset);
	sin_a = sin(player->angle + offset);
	i = 0;
	while (!find_wall(data, player, i, cos_a, sin_a))
	{
		// mlx_pixel_put(data->mlx, data->window,
		// 	cos_a * i + player->posx, 
		// 	sin_a * i + player->posy, 0x007777);
		i++;
	}
	place_wall(data, i, offset, iter);
}

void	show_rays(t_data *data, t_player *player)
{
	double	offset;
	double	i;

	base_bg(data);
	offset = - FOV / 2;
	while (offset < FOV / 2)
	{
		draw_ray(data, player, offset, i);
		i++;
		offset += 0.2 / (FOV * 180 / M_PI);
	}
}
