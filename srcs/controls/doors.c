/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:49:51 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/14 10:58:44 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	toggle_door(t_data *data, t_player *player)
{
	char	c;

	c = data->mapi->map
	[player->sy][player->sx];
	if (c == 'O')
	{
		data->map->door_anim = 1;
		data->mapi->map
		[player->sy][player->sx] = 'C';
		data->map->matrix
		[player->sy][player->sx] = 'C';
		data->map->anim_x = player->sx;
		data->map->anim_y = player->sy;
	}
	else if (c == 'C')
	{
		data->map->door_anim = 2;
		data->mapi->map
		[player->sy][player->sx] = 'O';
		data->map->anim_x = player->sx;
		data->map->anim_y = player->sy;
	}
}

static int	mini_dda(t_data *data, t_player *player)
{
	int	i;
	int	check_space[2];

	i = 1;
	check_space[0] = player->posx;
	check_space[1] = player->posy;
	while (i < data->tilesize && !is_door_or_wall(data->mapi->map
			[check_space[1] / data->tilesize][check_space[0] / data->tilesize]))
	{
		check_space[0] = player->posx + (int)(i * cos(player->angle));
		check_space[1] = player->posy + (int)(i * sin(player->angle));
		i++;
	}
	player->sx = check_space[0] / data->tilesize;
	player->sy = check_space[1] / data->tilesize;
	return (i);
}

void	check_door(t_data *data)
{
	int	dist;

	dist = mini_dda(data, data->player);
	if (dist < data->tilesize && dist > 1)
		toggle_door(data, data->player);
}
