/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_forwards.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:52:05 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/11 11:27:53 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	forward_collision(t_data *data, t_player *player)
{
	if (data->mapi->map
		[(int)((player->posy - player->half / 2 + MOVE_SPD * player->sin_a) /
		data->tilesize)]
		[(int)((player->posx - player->half / 2 + MOVE_SPD * player->cos_a) /
		data->tilesize)] != '1' && data->mapi->map
		[(int)((player->posy + 7 * player->half / 5 + MOVE_SPD * player->sin_a) /
		data->tilesize)]
		[(int)((player->posx + 7 * player->half / 5 + MOVE_SPD * player->cos_a) /
		data->tilesize)] != '1')
		return (0);
	return (1);
}

int	h_forward_collision(t_data *data, t_player *player)
{
	if (data->mapi->map
		[(int)((player->posy - player->half / 2) /
		data->tilesize)]
		[(int)((player->posx - player->half / 2 + MOVE_SPD * player->cos_a) /
		data->tilesize)] != '1' && data->mapi->map
		[(int)((player->posy + 7 * player->half / 5) /
		data->tilesize)]
		[(int)((player->posx + 7 * player->half / 5 + MOVE_SPD * player->cos_a) /
		data->tilesize)] != '1')
		return (0);
	return (1);
}

int	v_forward_collision(t_data *data, t_player *player)
{
	if (data->mapi->map
		[(int)((player->posy - player->half / 2 + MOVE_SPD * player->sin_a) 
		/ data->tilesize)]
		[(int)((player->posx - player->half / 2) / data->tilesize)]
		!= '1' && data->mapi->map
		[(int)((player->posy + 7 * player->half / 5 + MOVE_SPD * player->sin_a) 
		/ data->tilesize)]
		[(int)((player->posx + 7 * player->half / 5) / data->tilesize)]
		!= '1')
		return (0);
	return (1);
}
