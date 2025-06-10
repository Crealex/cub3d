/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:32:16 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/10 15:51:50 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_rotate_left(t_data *data)
{
	data->player->angle -= TURN_SPD;
	data->player->cos_a = cos(data->player->angle);
	data->player->sin_a = sin(data->player->angle);
}

void	player_rotate_right(t_data *data)
{
	data->player->angle += TURN_SPD;
	data->player->cos_a = cos(data->player->angle);
	data->player->sin_a = sin(data->player->angle);
}
