/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:46:13 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/12 19:17:50 by alexandre        ###   ########.fr       */
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

static double	find_wall_size(t_data *data, double dist)
{
	double	wall_size;

	wall_size = data->winsize_y / dist;
	if (wall_size <= 0.0001)
		wall_size = 0.0001;
	return (wall_size);
}

static int	define_tex_x(t_hit hit, t_img *tex)
{
	double	impact;
	int		res;

	if (hit.side == 'W' || hit.side == 'E')
		impact = fmod(hit.y * TILE_SIZE, TILE_SIZE);
	else
		impact = fmod(hit.x * TILE_SIZE, TILE_SIZE);
	res = (impact / TILE_SIZE) * tex->width;
	if (hit.side == 'W' || hit.side == 'S')
		res = tex->width - res - 1;
	res = fmax(0, fmin(res, tex->width - 1));
	return (res);
}

static void	put_pixel(t_data *data, int x, int y, unsigned int color)
{
	t_background	*bg;

	bg = data->background;
	if (x >= 0 && x < data->winsize_x && y >= 0 && y < data->winsize_y)
	{
		*(unsigned int *)(bg->addr
				+ (x * (bg->bpp / 8))
				+ y * bg->line_size) = color;
	}
}

void	place_wall(t_data *data, t_hit hit, int x)
{
	double			wall_size;
	int				i;
	t_img			*tex;
	unsigned int	pixel;

	wall_size = find_wall_size(data, hit.dist);
	hit.wall_size = wall_size;
	tex = NULL;
	tex = define_tex(hit, data);
	i = -wall_size / 2;
	if (i < -data->winsize_y / 2)
		i = -data->winsize_y / 2;
	hit.tex_x = define_tex_x(hit, tex);
	while (i < wall_size / 2 && i < data->winsize_y / 2)
	{
		hit.i = i;
		pixel = define_pix_texture(hit, data, tex);
		put_pixel(data, x, data->winsize_y / 2 + i, pixel);
		i++;
		handle_timer(data);
	}
	if (hit.door_hit && (int)(hit.door_hit->x) == data->map->anim_x)
		anim_door(data, hit, x);
}
