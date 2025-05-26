/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:19:00 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/26 16:27:04 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ***** DEBUG FCT *****


void print_file(char **file)
{
	int i;

	i = 0;
	printf("*****PRINT FILE*****\n");
	while (file[i])
	{
		printf("%d: %s\n", i, file[i]);
		i++;
	}
}

// *********************

int	count_line(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (count);
		count++;
	}
	return (count);
}


int check_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
	{
		perror(RED"Error,\nOne argument is excepted!!\n"RESET);
		return (0);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		perror(RED"Error,\nInvalid path with a map!\n"RESET);
		return (0);
	}
	while (argv[1][i])
		i++;
	i--;
	if (i < 5 || argv[1][i] != 'b'  || argv[1][i - 1] != 'u'
			|| argv[1][i - 2] != 'c' || argv[1][i - 3] != '.')
	{
		perror(RED"Error,\nInvalid extension!\n"RESET);
		return (0);
	}
	return (1);
}

t_map	*parsing(int argc, char **argv)
{
	t_map *map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!check_args(argc, argv) || !check_file(argv[1]))
		return (NULL);
	(void)map;
	return (map);
}
