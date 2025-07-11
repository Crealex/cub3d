/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:46:13 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/11 10:09:06 by alexandre        ###   ########.fr       */
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
		impact = fmod(hit.x *TILE_SIZE, TILE_SIZE);
	res = (impact / TILE_SIZE) * tex->width;
	if (hit.side == 'W' || hit.side == 'S')
		res = tex->width - res - 1;
	res = fmax(0, fmin(res, tex->width - 1));
	return (res);

}

static void	handle_timer(t_data *data)
{
	if (data->map->door_anim == 1 || data->map->door_anim == 2)
		data->map->timer += 1;
	if (data->map->timer > 100000000)
	{
		data->map->door_anim = 0;
		data->map->timer = 0;
	}
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

void	anim_door(t_data *data, t_hit hit, double offset, int x)
{
	double			door_size;
	t_img			*door_tex;
	int				j;
	unsigned int	door_pix;

	door_size = find_wall_size(data, hit.door_hit->dist, offset);
	hit.door_hit->wall_size = door_size;
	door_tex = define_tex(*hit.door_hit, data);
	if (door_tex == NULL || !door_tex->addr)
		return ;
	hit.door_hit->tex_x = define_tex_x(*hit.door_hit, door_tex);
	j = -door_size / 2;
	if (j < -data->winsize_y / 2)
		j = -data->winsize_y / 2;
	while (j < door_size / 2 && j < data->winsize_y / 2)
	{
		hit.door_hit->i = j;
		door_pix = define_pix_texture(*hit.door_hit, data, door_tex);
		if (door_pix != 0xff000000)
			put_pixel(data, x, data->winsize_y / 2 + j, door_pix);
		j++;
	}
}

void	place_wall(t_data *data, t_hit hit, double offset, int x)
{
	double			wall_size;
	int				i;
	t_img			*tex;
	unsigned int	pixel;

	wall_size = find_wall_size(data, hit.dist, offset);
	hit.wall_size = wall_size;
	tex = define_tex(hit, data);
	i = - wall_size / 2;
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
		anim_door(data, hit, offset, x);
}

