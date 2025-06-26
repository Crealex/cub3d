/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:25:19 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/26 17:10:32 by atomasi          ###   ########.fr       */
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

unsigned int	define_pix_texture(t_hit hit, t_data *data, int i, double wall_size)
{
	unsigned int	color;
	int				tex_x;
	int				tex_y;
	double			impact;

	//color = *(unsigned int *)(addr + (tex_y * line_size) + (tex_x * (bpp / 8)));
	// CODE DO CRASH THE PC`
	color = 0;
	if (hit.side == 0)
		impact = fmod(hit.y, 25);
	else
		impact = fmod(hit.x, 25);
	tex_x = (int)(impact / 25) * data->textures->ea->width;
	if ((hit.side == 0 && hit.ray_x > 0) || (hit.side == 1 && hit.ray_y < 0))
		tex_x = data->textures->ea->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= data->textures->ea->width)
		tex_x = data->textures->ea->width - 1;
	tex_y = (int)(i + wall_size / 2) * data->textures->ea->height / wall_size;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= data->textures->ea->height)
		tex_y = data->textures->ea->height - 1;
	if (!data->textures || !data->textures->ea->addr || !data->textures->ea->line_size || !data->textures->ea->bpp )
		return (0xffffffff);
	color = *(unsigned int *)(data->textures->ea->addr + (tex_y * data->textures->ea->line_size) + (tex_x * (data->textures->ea->bpp / 8)));
	//printf("color: %d\n", color);
	return (color);
}
