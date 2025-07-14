/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:41:16 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/14 14:28:13 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	find_return_value(char c)
{
	if (c == 'N')
		return (3);
	else if (c == 'S')
		return (1);
	else if (c == 'W')
		return (2);
	else if (c == 'E')
		return (0);
	return (-1);
}

int	find_orientation(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'W')
				break ;
			j++;
		}
		if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			break ;
		i++;
		j = 0;
	}
	return (find_return_value(map[i][j]));
}

void	fill_matrix(t_map *map, char **file)
{
	int	i;
	int	imap;

	i = find_begin(file);
	imap = 0;
	map->matrix = ft_calloc(sizeof(char *), tab_size(file) + 1);
	while (file[i] && file[i][0] != '\n')
	{
		map->matrix[imap] = ft_strdup(file[i]);
		imap++;
		i++;
	}
	map->matrix[imap] = NULL;
	map->player_start = find_orientation(map->matrix);
}
