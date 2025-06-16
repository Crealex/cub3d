/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:59:53 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/16 14:01:55 by psoulie          ###   ########.fr       */
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

void	draw_ray(t_data *data, t_player *player, double offset, double iter, t_map *map)
{
	double	dist;

	data->background->cos_a = cos(player->angle + offset);
	data->background->sin_a = sin(player->angle + offset);
	dist = ray_cast(player, map, offset);
	place_wall(data, dist, offset, iter);
}

void	show_rays(t_data *data, t_player *player)
{
	double	offset;
	double	i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	base_bg(data);
	offset = - FOV / 2;
	map->matrix = malloc(8 * sizeof(char *));
	map->matrix[7] = NULL;
	map->matrix[0] = "1111111111111";
	map->matrix[1] = "1000000001001";
	map->matrix[2] = "1111001101001";
	map->matrix[3] = "1111001111101";
	map->matrix[4] = "1100000001101";
	map->matrix[5] = "11E0000000001";
	map->matrix[6] = "1111111111111";
	while (offset < FOV / 2)
	{
		draw_ray(data, player, offset, i, map);
		i++;
		offset += 0.01 / (FOV * 180 / M_PI);
	}
	free(map->matrix);
	free(map);
}
