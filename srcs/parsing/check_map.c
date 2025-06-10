/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:07:32 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/10 10:40:06 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_begin(char **file)
{
	int	i;

	i = 0;
	while (file[i] && !is_map_begin(file[i]))
	{
		i++;
	}
	return (i);
}

int	check_zero(int i, char **file, int no)
{
	if (file[no][i + 1] && file[no][i - 1] && file[no - 1] && file[no + 1]
		&& file[no - 1][i] && file[no + 1][i])
	{
		if (file[no][i + 1] == ' ' || file[no][i + 1] == '\n')
			return (0);
		if (file[no][i - 1] == ' ' || file[no][i - 1] == '\n')
			return (0);
		if (file[no - 1][i] == ' ' || file[no - 1][i] == '\n')
			return (0);
		if (file[no + 1][i] == ' ' || file[no + 1][i] == '\n')
			return (0);
		return (1);
	}
	return (0);
}

int	check_line(char *line, char **file, int no)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (line[i])
	{
		if (line[i] == '0')
		{
			if (!check_zero(i, file, no))
				return (perror(RED"Error,\nMap doesn't close !"RESET), 0);
		}
		else if (is_dir(line[i]))
			player++;
		if (player > 1 || (!is_dir(line[i]) && line[i] != '0' && line[i] != '1'
				&& line[i] != ' ' && line[i] != '\n'))
			return (perror(RED"Error,\nInvalid char in the map !\n"RESET), 0);
		i++;
	}
	return (1);
}

int	check_map(char **file)
{
	int	i;

	i = find_begin(file);
	while (file[i])
	{
		if (!check_line(file[i], file, i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
