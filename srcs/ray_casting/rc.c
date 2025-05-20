/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/20 17:19:16 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_square(int side, int x, int y, int colour, void *mlx, void *window)
{
	int	xi = 0;
	int	yi = 0;

	while (yi < side)
	{
		xi = 0;
		while (xi < side)
		{
			mlx_pixel_put(mlx, window, x + xi, y + yi, colour);
			xi++;
		}
		yi++;
	}
}

void on_keypress(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	test()
{

	void	*window;
	void	*mlx;
	long	i = 0;
	int		key = 65307;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1600, 2000, "hello");
	mlx_hook(window, 02, 1L<<0, on_keypress, NULL);
	mlx_hook(window, 17, 0, exit, &i);
	put_square(200, 1000, 1000, 0xFF0000, mlx, window);
	mlx_loop(mlx);
}