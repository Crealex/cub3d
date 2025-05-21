/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:05:43 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 20:05:59 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	on_keyrelease(int keycode, t_data *data)
{
	if (keycode == W)
		data->player->w = 0;
	if (keycode == A)
		data->player->a = 0;
	if (keycode == D)
		data->player->d = 0;
	if (keycode == S)
		data->player->s = 0;
	return (0);
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
		data->player->w = 1;
	if (keycode == A)
		data->player->a = 1;
	if (keycode == D)
		data->player->d = 1;
	if (keycode == S)
		data->player->s = 1;
	return (0);
}

int	fuck(int tamere)
{
	exit(tamere);
}

void	set_hooks(t_data *data)
{
	int tamere = 0;
	mlx_hook(data->window, 02, 1L<<0, on_keypress, data);
	mlx_hook(data->window, 17, 0, fuck, &tamere);
	mlx_hook(data->window, 03, 1L<<1, on_keyrelease, data);
}
