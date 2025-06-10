/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:42:17 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/10 10:51:39 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rgb(char *line)
{
	int	value;
	int	i;
	int	count;

	value = 0;
	i = 2;
	count = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		value = ft_atoi(&line[i]);
		if (value < 0 || value > 255)
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] && line[i] != ',' && line[i] != '\n')
			return (0);
		count++;
		i++;
	}
	if (count != 3)
		return (0);
	return (1);
}

t_elem	check_colours_format(char *line, t_elem base)
{
	t_elem	elem;

	cpy_elem(base, &elem);
	if (!ft_strncmp(line, "F ", 2))
	{
		if (!check_rgb(line))
		{
			perror(RED"Error, \nBad rgb format !\n");
			return (elem.f = -1, elem);
		}
		elem.f++;
		return (elem);
	}
	if (!check_rgb(line))
	{
		perror(RED"Error, \nBad rgb format !\n");
		return (elem.c = -1, elem);
	}
	elem.c++;
	return (elem);
}

int	check_nb_elem(t_elem elem, int mode)
{
	if (mode == 1)
	{
		if (elem.c != -1 && elem.ea != -1 && elem.f != -1 && elem.no != -1
			&& elem.so != -1 && elem.we != -1)
			return (1);
		return (0);
	}
	if (elem.c == 1 && elem.ea == 1 && elem.f == 1 && elem.no == 1
		&& elem.so == 1 && elem.we == 1)
		return (1);
	return (0);
}

int	check_elem(char **file)
{
	int		i;
	t_elem	elem;

	i = 0;
	init_elem(&elem);
	while (file[i])
	{
		if (!ft_strncmp(file[i], "NO ", 3) || !ft_strncmp(file[i], "SO ", 3)
			|| !ft_strncmp(file[i], "WE ", 3) || !ft_strncmp(file[i], "EA ", 3))
			elem = check_texture_path(file[i], elem);
		else if (!ft_strncmp(file[i], "C ", 2) || !ft_strncmp(file[i], "F ", 2))
			elem = check_colours_format(file[i], elem);
		else if (is_map_begin(file[i]))
			break ;
		else
			return (perror(RED"Bad element in file !\n"RESET), 0);
		if (!check_nb_elem(elem, 1))
			return (0);
		i++;
	}
	if (!check_nb_elem(elem, 0))
		return (perror(RED"Missing element in file !\n"RESET), 0);
	return (1);
}
