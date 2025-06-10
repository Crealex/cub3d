/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:19:00 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/10 13:49:43 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		free(line);
		count++;
	}
	return (count);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr_fd(RED"Error,\nOne argument is excepted!!\n"RESET, 2);
		return (0);
	}
	if (!try_open(argv[1]))
	{
		perror(RED"Error,\nInvalid path with a map!\n"RESET);
		return (0);
	}
	while (argv[1][i])
		i++;
	i--;
	if (i < 5 || argv[1][i] != 'b' || argv[1][i - 1] != 'u'
			|| argv[1][i - 2] != 'c' || argv[1][i - 3] != '.')
	{
		ft_putstr_fd(RED"Error,\nInvalid extension!\n"RESET, 2);
		return (0);
	}
	return (1);
}

t_map	*parsing(int argc, char **argv)
{
	t_map	*map;
	char	**file;

	if (!check_args(argc, argv))
		return (NULL);
	file = fill_file(argv[1]);
	if (!file || !check_file(file))
		return (clean_exit(file, NULL), NULL);
	print_file(file);
	map = fill_struct(file);
	if (!map)
		return (clean_exit(file, map), NULL);
	free_double_tab(file);
	return (map);
}
