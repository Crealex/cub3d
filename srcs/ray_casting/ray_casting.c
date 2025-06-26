/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:46:13 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/26 16:14:56 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	base_bg(t_data *data)
{
	int				i;
	int				j;
	t_background	*bg;

	bg = data->background;
	i = 0;
	while (i < data->winsize_y)
	{
		j = 0;
		while (j < data->winsize_x)
		{
			if (i < data->winsize_y / 2)
				*(int *)(bg->addr + j * (bg->bpp / 8) + i * bg->line_size)
				= data->map->ceiling;
			else
				*(int *)(bg->addr + j * (bg->bpp / 8) + i * bg->line_size)
				= data->map->floor;
			j++;
		}
		i++;
	}
}

double	find_wall_size(t_data *data, double dist, double offset)
{
	double	wall_size;
	double	angle;
	double	perp_dist;

	angle = M_PI / 2 - offset;
	perp_dist = sin(angle) * dist;
	wall_size = data->winsize_y / (perp_dist);
	if (wall_size <= 0)
		wall_size = 0.1;
	if (wall_size > data->winsize_y)
		wall_size = data->winsize_y;
	return (wall_size);
}

void	place_wall(t_data *data, t_hit hit, double offset, double iter)
{
	t_background	*bg;
	double			wall_size;
	int				x;
	int				i;

	(void)iter;
	bg = data->background;
	wall_size = find_wall_size(data, hit.dist, offset);
	i = - wall_size / 2;
	while (i < wall_size / 2)
	{
		x = (int)((offset + FOV / 2) * data->winsize_x);
			if (x < data->winsize_x )
				*(unsigned int *)(bg->addr + (x * (bg->bpp / 8)) + (data->winsize_y / 2 + i) * bg->line_size) = define_pix_texture(hit, data, i, wall_size);//0xA19CB3;//define pix_texture
		i++;
	}
}
