/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:36:54 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 14:25:38 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_square(t_square *square)
{
	int		i;
	int		j;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;

	addr = mlx_get_data_addr(square->img, &bpp, &line_size, &endian);
	i = 0;
	while (i < square->side)
	{
		j = 0;
		while (j < square->side)
		{
			*(unsigned int *)(addr + i * line_size + j * (bpp / 8)) = square->colour;
			j++;
		}
		i++;
	}
}

static t_square	*square_init(t_data *data)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	square->angle = 0;
	square->colour =  0xFF0000;
	square->side = 100;
	square->img = mlx_new_image(data->mlx, square->side, square->side);
	fill_square(square);
	return (square);
}

t_data	*data_init()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 2000, 1600, \
		"dont mind me im just a square");
	data->player = square_init(data);
	return (data);
}
