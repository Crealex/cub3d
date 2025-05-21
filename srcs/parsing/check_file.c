/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:34:58 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/21 16:39:07 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


char *extract_path(char *file)
{
	int i;
	int ipath;
	char *path;

	i = 3;
	ipath = 0;
	path = ft_calloc(sizeof(char), ft_strlen(file) - 3);
	while (file[i])
		path[ipath++] = file[i++];
	path[ipath] = '\0';
	return (path);
}
int check_path_and_ext(char *file)
{
	int i;
	int length;
	char *path;

	i = 0;
	length = ft_strlen(file);
	path = extract_path(file);
	if (length < 5 || file[3] != '.' || file[4] != '/'
			|| open(path, O_RDONLY) == -1)
	{
		perror(RED"Error,\nInvalid texture path !\n"RESET);
		free(path);
		return (0);
	}
	if (file[length - 1] != 'm' || file[length - 2] != 'p'
			|| file[length - 3] != 'x' || file[length - 4] != '.')
	{
		perror(RED"Error,\nInvlaid extention fromat texture file !\n"RESET);
		free(path);
		return (0);
	}
	free(path);
	return (1);
}

t_elem check_texture_path(char *file, t_elem base)
{
	t_elem	elem;

	cpy_elem(base, &elem);
	if (!ft_strncmp(file, "NO ", 3))
	{
		if (!check_path_and_ext(file))
			return (elem.no = -1, elem);
		return (elem.no++, elem);
	}
	else if (!ft_strncmp(file, "SO ", 3))
	{
		if (!check_path_and_ext(file))
			return (elem.so = -1, elem);
		return (elem.so++, elem);
	}
	else if (!ft_strncmp(file, "WE ", 3))
	{
		if (!check_path_and_ext(file))
			return (elem.we = -1, elem);
		return (elem.we++, elem);
	}
	if (!check_path_and_ext(file))
		return (elem.so = -1, elem);
	return (elem.so++, elem);
}

int	check_rgb(char *line)
{
	int	value;
	int	i;
	int count;

	value = 0;
	i = 2;
	count = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		value = ft_atoi(line[2]);
		if (value < 0 || value > 255)
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] && line[i] != ',' && line[i] != '\n')
			return (0);
		count++;
	}
	if (count != 3)
		return (0);
	return (1);
}

t_elem check_colours_format(char *line, t_elem base)
{
	t_elem	elem;
	int		i;

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

int check_nb_elem(t_elem elem, int mode)
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
	int i;
	int j;
	t_elem elem;

	i = 0;
	j = 0;
	init_elem(&elem);
	while (file[i][j])
	{
		if (!ft_strncmp(file[i], "NO ", 3) || !ft_strncmp(file[i], "SO ", 3)
			|| !ft_strncmp(file[i], "WE ", 3) || !ft_strncmp(file[i], "EA ", 3))
		{
			elem = check_texture_path(file[i], elem);
		}
		else if (!ft_strncmp(file[i], "C ", 2) || !ft_strncmp(file[i], "F ", 2))
			elem = check_colours_format(file[i], elem);
		else if (file[i][j] == ' ' || file[i][j] == '\n')
			continue;
		else
			break;
		if (!check_nb_elem(elem, 1))
			return (0);
	}
	// si bon nombre d'elem = good sinon pas good
}

char	**fill_file(char *path)
{
	char	**file;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	file = ft_calloc(count_line(fd), sizeof(char *));
	if (!file)
		return (NULL);
	close(fd);
	fd = open(path, O_RDONLY);
	i = 0;
	while (1)
	{
		file[i] = get_next_line(fd);
		if (!file[i])
			break;
		i++;
	}
	print_file(file);
	// check si les 4 paths de texture sont valide
	// check si les couleurs pour le sol et le plafond sont valides
	// check si le map est bien fermée
	// check si le joueur est bien mis
	// check si le chemin de la map est valide
	return (file);
}

int	check_file(char *path)
{
	char **file;

	file = fill_file(path);
	if (!check_elem(file))
		return (0);
	if (!check_map(file))
		return (0);
}