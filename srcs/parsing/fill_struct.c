/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:33:55 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/02 15:43:16 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*find_path(char *tofind, char **file)
{
	int i;

	i = 0;
	while(file[i])
	{
		if (!ft_strncmp(file[i], tofind, 2))
			return (ft_strdup(file[i]));
		i++;
	}
	return (NULL);
}

t_map	*fill_struct(char **file)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	init_map(map);
	map->no_path = find_path("NO", file);
	//remplir les paths
	//remplir les rgb
	//remplir le start du joueur
	//remplir la matrice de la map
}