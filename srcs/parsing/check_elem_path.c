/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:48:33 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/26 11:49:11 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *extract_path(char *file)
{
	int i;
	int ipath;
	char *path;

	i = 3;
	ipath = 0;
	path = ft_calloc(sizeof(char), ft_strlen(file) - 3);
	while (file[i] && file[i] != '\n')
		path[ipath++] = file[i++];
	path[ipath] = '\0';
	return (path);
}
int check_path_and_ext(char *file)
{
	int length;
	char *path;

	length = ft_strlen(file);
	path = extract_path(file);
	//printf("open %s ? : %d\n", path, open("./assets/textures/no.xpm", O_RDONLY));
	if (length < 5 || file[3] != '.' || file[4] != '/'
			|| open(path, O_RDONLY) == -1)
	{
		perror(RED"Error,\nInvalid texture path !\n"RESET);
		free(path);
		return (0);
	}
	//printf("file[%i] = %c", length - 2, file[length - 2]);
	if (file[length - 2] != 'm' || file[length - 3] != 'p'
			|| file[length - 4] != 'x' || file[length - 5] != '.')
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