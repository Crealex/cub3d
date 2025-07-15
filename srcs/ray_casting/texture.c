/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:25:19 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/15 10:20:46 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_img	*side_init(t_data *data, char *path, t_texture *tex)
{
	t_img	*res;

	res = ft_calloc(sizeof(t_img), 1);
	if (!res)
	{
		ft_putstr_fd("Error allocating memory for t_img", 2);
		exit(EXIT_FAILURE);
	}
	res->path = ft_strdup(path);
	res->img = mlx_xpm_file_to_image(data->mlx, res->path, &res->width,
			&res->height);
	if (!res->img)
	{
		ft_putstr_fd(RED"Error,\nInvalid xpm file\n"RESET, 2);
		free_tex(tex, data);
		free(res->path);
		mlx_destroy_image(data->mlx, res->img);
		free(res);
		proper_exit(data);
	}
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->line_size,
			&res->endian);
	return (res);
}

t_texture	*textures_init(t_data *data)
{
	t_texture	*tex;

	tex = ft_calloc(sizeof(t_texture), 1);
	if (!tex)
	{
		ft_putstr_fd("Error allocating memory for textures", 2);
		exit(EXIT_FAILURE);
	}
	tex->ea = side_init(data, data->map->ea_path, tex);
	tex->no = side_init(data, data->map->no_path, tex);
	tex->so = side_init(data, data->map->so_path, tex);
	tex->we = side_init(data, data->map->we_path, tex);
	tex->door = side_init(data, "./assets/textures/door.xpm", tex);
	tex->door_1 = side_init(data, "./assets/textures/door_1.xpm", tex);
	tex->door_2 = side_init(data, "./assets/textures/door_2.xpm", tex);
	tex->door_3 = side_init(data, "./assets/textures/door_3.xpm", tex);
	tex->door_4 = side_init(data, "./assets/textures/door_4.xpm", tex);
	tex->door_5 = side_init(data, "./assets/textures/door_5.xpm", tex);
	tex->door_6 = side_init(data, "./assets/textures/door_6.xpm", tex);
	tex->door_7 = side_init(data, "./assets/textures/door_7.xpm", tex);
	tex->door_8 = side_init(data, "./assets/textures/door_8.xpm", tex);
	tex->door_9 = side_init(data, "./assets/textures/door_9.xpm", tex);
	tex->door_10 = side_init(data, "./assets/textures/door_10.xpm", tex);
	return (tex);
}

t_img	*define_tex(t_hit hit, t_data *data)
{
	t_img	*tex;

	if (hit.type == 'C' || hit.type == 'O')
	{
		if (data->map->door_anim == 1)
			tex = display_anim_close(data);
		else if (data->map->door_anim == 2)
			tex = display_anim_open(data);
		else
			tex = data->textures->door;
		return (tex);
	}
	if (hit.side == 'W')
		tex = data->textures->we;
	else if (hit.side == 'E')
		tex = data->textures->ea;
	else if (hit.side == 'N')
		tex = data->textures->no;
	else if (hit.side == 'S')
		tex = data->textures->so;
	else
		return (NULL);
	return (tex);
}

unsigned int	define_pix_texture(t_hit hit, t_data *data, t_img *tex)
{
	unsigned int	color;
	int				tex_x;
	int				tex_y;

	(void)data;
	color = 0;
	tex_x = hit.tex_x;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	tex_y = (int)(hit.i + hit.wall_size / 2) *tex->height / hit.wall_size;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	if (!tex || !tex->addr || !tex->line_size || !tex->bpp)
		return (0xffffffff);
	color = *(unsigned int *)(tex->addr + (tex->line_size * tex_y) + (tex_x
				* (tex->bpp / 8)));
	return (color);
}
