/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:36:32 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/17 14:45:47 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_map_begin(char *line)
{
	int	i;
	int	one;

	i = 0;
	one = 0;
	if (!line)
		return (0);
	while (line && line[i] == ' ')
		i++;
	while (line && (line[i] == '1' || line[i] == '0'))
	{
		one++;
		i++;
	}
	if ((!line[i] || line[i] == '\n') && one > 0)
		return (1);
	return (0);
}

int	tab_size(char **file)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (file[i])
	{
		while (file[i][j] == ' ')
			j++;
		count++;
		i++;
		j = 0;
	}
	return (count);
}

int	len_wspace(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!(str[i] && str[i + 1] && str[i] == ' ' && str[i + 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

int	is_dir(char c, int i, char **file, int no)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (!check_zero(i, file, no))
		{
			ft_putstr_fd(RED"Error,\nBad player position\n"RESET, 2);
			free_double_tab(file);
			exit(1);
		}
		return (1);
	}
	return (0);
}

int	try_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
