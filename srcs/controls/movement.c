/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:00:53 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/14 10:56:45 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	loop(t_data *data)
{
	if (data->player->left)
		player_rotate_left(data);
	if (data->player->right)
		player_rotate_right(data);
	if (data->player->w)
		player_move_forwards(data);
	if (data->player->a)
		player_move_left(data);
	if (data->player->d)
		player_move_right(data);
	if (data->player->s)
		player_move_backwards(data);
	refresh_window(data);
	return (0);
}

void	player_move_forwards(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_empty(data->mapi->map
			[(int)((player->posy + MOVE_SPD * player->sin_a) / data->tilesize)]
		[(int)((player->posx + MOVE_SPD * player->cos_a) / data->tilesize)]))
	{
		player->posx += MOVE_SPD * player->cos_a;
		player->posy += MOVE_SPD * player->sin_a;
	}
	else if (is_empty(data->mapi->map
			[(int)((player->posy) / data->tilesize)]
		[(int)((player->posx + MOVE_SPD * player->cos_a) / data->tilesize)]))
		player->posx += MOVE_SPD * player->cos_a;
	else if (is_empty(data->mapi->map
			[(int)((player->posy + MOVE_SPD * player->sin_a) / data->tilesize)]
		[(int)((player->posx) / data->tilesize)]))
		player->posy += MOVE_SPD * player->sin_a;
}

void	player_move_left(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_empty(data->mapi->map
			[(int)((player->posy - MOVE_SPD * player->cos_a) / data->tilesize)]
		[(int)((player->posx + MOVE_SPD * player->sin_a) / data->tilesize)]))
	{
		player->posx += MOVE_SPD * player->sin_a;
		player->posy -= MOVE_SPD * player->cos_a;
	}
	else if (is_empty(data->mapi->map
			[(int)((player->posy) / data->tilesize)]
		[(int)((player->posx + MOVE_SPD * player->sin_a) / data->tilesize)]))
		player->posx += MOVE_SPD * player->sin_a;
	else if (is_empty(data->mapi->map
			[(int)((player->posy - MOVE_SPD * player->cos_a) / data->tilesize)]
		[(int)((player->posx) / data->tilesize)]))
		player->posy -= MOVE_SPD * player->cos_a;
}

void	player_move_backwards(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_empty(data->mapi->map
			[(int)((player->posy - MOVE_SPD * player->sin_a) / data->tilesize)]
		[(int)((player->posx - MOVE_SPD * player->cos_a) / data->tilesize)]))
	{
		player->posx -= MOVE_SPD * player->cos_a;
		player->posy -= MOVE_SPD * player->sin_a;
	}
	else if (is_empty(data->mapi->map
			[(int)((player->posy) / data->tilesize)]
		[(int)((player->posx - MOVE_SPD * player->cos_a) / data->tilesize)]))
		player->posx -= MOVE_SPD * player->cos_a;
	else if (is_empty(data->mapi->map
			[(int)((player->posy - MOVE_SPD * player->sin_a) / data->tilesize)]
		[(int)((player->posx) / data->tilesize)]))
		player->posy -= MOVE_SPD * player->sin_a;
}

void	player_move_right(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (is_empty(data->mapi->map
			[(int)((player->posy + MOVE_SPD * player->cos_a) / data->tilesize)]
		[(int)((player->posx - MOVE_SPD * player->sin_a) / data->tilesize)]))
	{
		player->posx -= MOVE_SPD * player->sin_a;
		player->posy += MOVE_SPD * player->cos_a;
	}
	else if (is_empty(data->mapi->map
			[(int)((player->posy) / data->tilesize)]
		[(int)((player->posx - MOVE_SPD * player->sin_a) / data->tilesize)]))
		player->posx -= MOVE_SPD * player->sin_a;
	else if (is_empty(data->mapi->map
			[(int)((player->posy + MOVE_SPD * player->cos_a) / data->tilesize)]
		[(int)((player->posx) / data->tilesize)]))
		player->posy += MOVE_SPD * player->cos_a;
}
