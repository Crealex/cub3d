/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:25:19 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/25 22:50:14 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_img	side_init(t_data *data, t_img img)
{
	t_img	res;

	res.img = mlx_xpm_file_to_image(data->mlx, img.path, &img.width, &img.height);
	res.addr = mlx_get_data_addr(res.img, &res.bpp, &res.line_size, &res.endian);
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
	printf("data->map->ea_path: %s\n", data->map->ea_path);
	tex->ea.path = ft_strdup(data->map->ea_path);
	printf("tex->ea.path: %s\n", tex->ea.path);
	tex->ea = side_init(data, tex->ea);
	tex->no.path = ft_strdup(data->map->no_path);
	tex->no = side_init(data, tex->no);
	tex->so.path = ft_strdup(data->map->so_path);
	tex->so = side_init(data, tex->so);
	tex->we.path = ft_strdup(data->map->we_path);
	tex->we = side_init(data, tex->we);
	return (tex);
}

int	define_pix_texture(t_hit hit, t_data *data)
{
	t_texture	*textures;
	int color;

	textures = textures_init(data);
	//color = *(unsigned int *)(addr + (tex_y * line_size) + (tex_x * (bpp / 8)));
	// CODE DO CRASH THE PC`
	color = *(unsigned int *)(textures->ea.addr + (hit.y * textures->ea.line_size) + (hit.x * (textures->ea.bpp / 8)));
	printf("color: %d\n", color);
	return (color);
}