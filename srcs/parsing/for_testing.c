/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_testing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:09:09 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/14 10:34:07 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// JUST FOR TESTING !!!!!!!!!!!!!!!!!!!

#include <cub3d.h>

void	print_file(char **file)
{
	int	i;

	i = 0;
	printf("*****PRINT FILE*****\n");
	while (file[i] && !is_map_begin(file[i]))
	{
		printf("%d: %s\n", i, file[i]);
		i++;
	}
	while (file[i])
	{
		printf("%d: %s", i, file[i]);
		i++;
	}
	printf("\n");
}

void	print_struct(t_map *map)
{
	int	i;

	i = 0;
	printf("*****PRINT STRUCT*****\n");
	printf("no_path: %s\n", map->no_path);
	printf("so_path: %s\n", map->so_path);
	printf("we_path: %s\n", map->we_path);
	printf("ea_path: %s\n", map->ea_path);
	printf("floor: %x\n", map->floor);
	printf("ceiling: %x\n", map->ceiling);
	printf("player_start: %d\n", map->player_start);
	printf("matrix: \n");
	printf("timer: %f\n", map->timer);
	while (map->matrix[i])
	{
		printf("%s", map->matrix[i]);
		i++;
	}
	printf("\n**********\n");
}
