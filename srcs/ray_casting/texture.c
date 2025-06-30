/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:25:19 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/30 18:19:50 by atomasi          ###   ########.fr       */
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
	//printf("tex->ea.path: %s\n", tex->ea.path);
	tex->ea = side_init(data, data->map->ea_path);
	tex->no = side_init(data, data->map->no_path);
	tex->so = side_init(data, data->map->so_path);
	tex->we = side_init(data, data->map->we_path);
	return (tex);
}

t_img	*define_tex(t_hit hit, t_data *data)
{
	t_img	*tex;

	//printf("hit.side: %d, ray_x: %f, ray y: %f\n", hit.side, hit.ray_x, hit.ray_y);
	if (hit.side == 'W')
		tex = data->textures->we;
	else if (hit.side == 'E')
		tex =data->textures->ea;
	else if (hit.side == 'N')
		tex = data->textures->no;
	else
		tex = data->textures->so;
	return (tex);
}

unsigned int	define_pix_texture(t_hit hit, t_data *data, t_img *tex)
{
	unsigned int	color;
	int				tex_x;
	int				tex_y;

	//color = *(unsigned int *)(addr + (tex_y * line_size) + (tex_x * (bpp / 8)));
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
	if (!tex || !tex->addr || !tex->line_size || !tex->bpp )
		return (0xffffffff);
	color = *(unsigned int *)(tex->addr + (tex->line_size * tex_y) + (tex_x * (tex->bpp / 8)));
	//printf("color: %d\n", color);
	return (color);
}
