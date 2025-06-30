/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:46:13 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/30 18:28:57 by atomasi          ###   ########.fr       */
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

	// angle = M_PI / 2 - offset;
	// perp_dist = sin(angle) * dist;
	// wall_size = data->winsize_y / (perp_dist);
	// if (wall_size <= 0)
	// 	wall_size = 0.1;
	// if (wall_size > data->winsize_y)
	// 	wall_size = data->winsize_y;
	wall_size = data->winsize_y / dist;
	if (wall_size <= 0.0001)
		wall_size = 0.0001;
	if (wall_size > data->winsize_y)
		wall_size = data->winsize_y;
	return (wall_size);
}

static int	define_tex_x(t_hit hit, t_img *tex)
{
	double	impact;
	int		res;

	if (hit.side == 'W' || hit.side == 'E')
		impact = fmod(hit.y * TILE_SIZE, TILE_SIZE);
	else
		impact = fmod(hit.x *TILE_SIZE, TILE_SIZE);
	res = (impact / TILE_SIZE) * tex->width;
	if (hit.side == 'W' || hit.side == 'S')
		res = tex->width - res - 1;
	res = fmax(0, fmin(res, tex->width - 1));
	return (res);
}


void	place_wall(t_data *data, t_hit hit, double offset, int x)
{
	t_background	*bg;
	double			wall_size;
	//int				x;
	int				i;
	t_img			*tex;

	bg = data->background;
	wall_size = find_wall_size(data, hit.dist, offset);
	i = - wall_size / 2;
	hit.wall_size = wall_size;
	tex = define_tex(hit, data);
	hit.tex_x = define_tex_x(hit, tex);
	while (i < wall_size / 2)
	{
		hit.i = i;
		//x = (int)((offset + FOV / 2) * data->winsize_x);
			if (x < data->winsize_x )
				*(unsigned int *)(bg->addr + (x * (bg->bpp / 8)) + (data->winsize_y / 2 + i) * bg->line_size) = define_pix_texture(hit, data, tex);//0xA19CB3;//define pix_texture
		i++;
	}
}

