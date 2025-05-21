/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:05:43 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 14:25:35 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void on_keypress(int keycode, t_data *data)
{
	printf("%i\n", keycode);
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
		player_move_forwards(data);
	if (keycode == A)
		player_move_left(data);
	if (keycode == D)
		player_move_right(data);
	if (keycode == S)
		player_move_backwards(data);
	return (0);
}

void	set_hooks(t_data *data)
{
	int tamere = 0;
	mlx_hook(data->window, 02, 1L<<0, on_keypress, data);
	mlx_hook(data->window, 17, 0, exit, &tamere);
}
