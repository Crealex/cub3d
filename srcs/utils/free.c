/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:36:59 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/16 15:04:09 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_struct(t_map *map)
{
	free(map->no_path);
	free(map->ea_path);
	free(map->so_path);
	free(map->we_path);
	free_double_tab(map->matrix);
	free(map);
}

void	clean_exit(char **file, t_map *map)
{
	if (file)
		free_double_tab(file);
	if (map)
		free_struct(map);
}
