/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:19:25 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 20:28:45 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	loop(t_data *data)
{
	if (data->player->w)
		player_move_forwards(data);
	if (data->player->a)
		player_move_left(data);
	if (data->player->d)
		player_move_right(data);
	if (data->player->s)
		player_move_backwards(data);
	return (0);
}

void	player_move_forwards(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->posy -= 5;
	refresh_window(data);
}

void	player_move_left(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->posx -= 5;
	refresh_window(data);
}

void	player_move_backwards(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->posy += 5;
	refresh_window(data);
}

void	player_move_right(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->posx += 5;
	refresh_window(data);
}
