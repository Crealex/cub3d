/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:15:39 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 19:09:40 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int main()
{
	t_data	*data;

	data = data_init();
	set_hooks(data);
	refresh_window(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (0);
}
