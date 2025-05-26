/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:34:58 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/26 16:44:50 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	tab_size(char **file)
{
	int	i;
	int j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (file[i])
	{
		while (file[i][j] == ' ')
			j++;
		if (file[i][j] && file[i][j] != '\n')
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
	printf("in len_wspace\n");
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

char	**format_file(char **file, int j, int ires, int jres)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * tab_size(file));
	while (file[i])
	{
		if (file[i][j] && file[i][j] != '\n')
		{
			if (jres == 0)
				res[ires] = malloc(sizeof(char) * (len_wspace(file[i]) + 2));
			if (!(file[i][j] && file[i][j + 1] && file[i][j] == ' ' && file[i][j + 1] == ' '))
				if (!(jres == 0 && file[i][j] == ' '))
					res[ires][jres++] = file[i][j];
			j++;
		}
		if (jres > 0 && (!file[i][j] || file[i][j] == '\n'))
			res[ires++][jres] = '\0';
		if (!file[i][j] || file[i][j] == '\n')
		{
			j = 0;
			jres = 0;
			i++;
		}

	}
	return (free_double_tab(file), res[ires] = NULL, res);
}

char	**fill_file(char *path)
{
	char	**file;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	file = ft_calloc(count_line(fd) + 1, sizeof(char *));
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
	file[i] = NULL;
	file = format_file(file, 0, 0 , 0);
	print_file(file);

	return (file);
}

int	check_file(char *path)
{
	char **file;

	file = fill_file(path);
	(void)file;
	// if (!check_elem(file))
	// 	return (0);
	// if (!check_map(file))
	// 	return (0);
	return (1);
}