/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:25:19 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/11 11:09:00 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_img	*side_init(t_data *data, char *path)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	res->path = ft_strdup(path);
	res->img = mlx_xpm_file_to_image(data->mlx, res->path, &res->width, &res->height);
	res->addr = mlx_get_data_addr(res->img, &res->bpp, &res->line_size, &res->endian);
	return (res);
}

t_texture	*textures_init(t_data *data)
{
	t_texture *tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
	{
		perror("Error allocating memory for textures");
		exit(EXIT_FAILURE);
	}
	//printf("data->map->ea_path: %s\n", data->map->ea_path);
	tex->ea = side_init(data, data->map->ea_path);
	tex->no = side_init(data, data->map->no_path);
	tex->so = side_init(data, data->map->so_path);
	tex->we = side_init(data, data->map->we_path);
	tex->door = side_init(data, "./assets/textures/door.xpm");
	tex->door_1 = side_init(data, "./assets/textures/door_1.xpm");
	tex->door_2 = side_init(data, "./assets/textures/door_2.xpm");
	tex->door_3 = side_init(data, "./assets/textures/door_3.xpm");
	tex->door_4 = side_init(data, "./assets/textures/door_4.xpm");
	tex->door_5 = side_init(data, "./assets/textures/door_5.xpm");
	tex->door_6 = side_init(data, "./assets/textures/door_6.xpm");
	tex->door_7 = side_init(data, "./assets/textures/door_7.xpm");
	tex->door_8 = side_init(data, "./assets/textures/door_8.xpm");
	tex->door_9 = side_init(data, "./assets/textures/door_9.xpm");
	tex->door_10 = side_init(data, "./assets/textures/door_10.xpm");
	return (tex);
}

t_img	*display_anim_open(t_data *data)
{
	if (data->map->timer < 10000000)
		return (data->textures->door_1);
	else if (data->map->timer < 20000000)
		return (data->textures->door_2);
	else if (data->map->timer < 30000000)
		return (data->textures->door_3);
	else if (data->map->timer < 40000000)
		return (data->textures->door_4);
	else if (data->map->timer < 50000000)
		return (data->textures->door_5);
	else if (data->map->timer < 60000000)
		return (data->textures->door_6);
	else if (data->map->timer < 70000000)
		return (data->textures->door_7);
	else if (data->map->timer < 80000000)
		return (data->textures->door_8);
	else if (data->map->timer < 90000000)
		return (data->textures->door_9);
	else
	{
		data->map->matrix[data->player->sy][data->player->sx] = 'O';
		return (data->textures->door_10);
	}
}

t_img	*display_anim_close(t_data *data)
{
	if (data->map->timer < 10000000)
		return (data->textures->door_10);
	else if (data->map->timer < 20000000)
		return (data->textures->door_9);
	else if (data->map->timer < 30000000)
		return (data->textures->door_8);
	else if (data->map->timer < 40000000)
		return (data->textures->door_7);
	else if (data->map->timer < 50000000)
		return (data->textures->door_6);
	else if (data->map->timer < 60000000)
		return (data->textures->door_5);
	else if (data->map->timer < 70000000)
		return (data->textures->door_4);
	else if (data->map->timer < 80000000)
		return (data->textures->door_3);
	else if (data->map->timer < 90000000)
		return (data->textures->door_2);
	else
		return (data->textures->door_1);
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
		tex =data->textures->ea;
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
	tex_y = (int)(hit.i + hit.wall_size / 2) * tex->height / hit.wall_size;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	//printf("tex->heigth: %d\n", tex->height);
	if (!tex || !tex->addr || !tex->line_size || !tex->bpp)
		return (0xffffffff);
	//printf("tex->addr: %p, tex->line_size: %d, tex_x: %d, tex_y: %d, tex->bpp: %d\n", tex->addr, tex->line_size, tex_x, tex_y, tex->bpp);
	//printf("after\n");
	color = *(unsigned int *)(tex->addr + (tex->line_size * tex_y) + (tex_x * (tex->bpp / 8)));
	// if (data->map->door_anim == 1 || data->map->door_anim == 2)
	// 	printf("color: %x\n", color);
	return (color);
}
