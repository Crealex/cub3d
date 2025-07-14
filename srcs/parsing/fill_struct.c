/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:33:55 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/14 14:22:58 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*find_path(char *tofind, char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (!ft_strncmp(file[i], tofind, 2))
			return (ft_strdup(&file[i][3]));
		i++;
	}
	return (NULL);
}

void	fill_path(t_map *map, char **file)
{
	map->no_path = find_path("NO", file);
	map->so_path = find_path("SO", file);
	map->ea_path = find_path("EA", file);
	map->we_path = find_path("WE", file);
}

int	*extract_colours(char *target, char **file)
{
	int	*res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	res = ft_calloc(sizeof(int), 3);
	if (!res)
		return (NULL);
	while (file[i] && ft_strncmp(target, file[i], 1))
		i++;
	res[2] = ft_atoi(&file[i][1]);
	while (file[i][j] && file[i][j] != ',')
		j++;
	j++;
	res[1] = ft_atoi(&file[i][j]);
	while (file[i][j] && file[i][j] != ',')
		j++;
	j++;
	res[0] = ft_atoi(&file[i][j]);
	return (res);
}

void	fill_rgb(t_map *map, char **file)
{
	int	*f_rgb;
	int	*c_rgb;

	f_rgb = extract_colours("F", file);
	c_rgb = extract_colours("C", file);
	map->floor = (f_rgb[2] << 16) + (f_rgb[1] << 8) + (f_rgb[0]);
	map->ceiling = (c_rgb[2] << 16) + (c_rgb[1] << 8) + (c_rgb[0]);
	free(f_rgb);
	free(c_rgb);
}

t_map	*fill_struct(char **file)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map);
	fill_path(map, file);
	fill_rgb(map, file);
	fill_matrix(map, file);
	return (map);
}
