/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:34:58 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/30 11:54:26 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_var(int *i, int *j, int *jres)
{
	*i = *i + 1;
	*j = 0;
	*jres = 0;
}

void fill_map(char **file, char **res, int *ires, int i)
{
	int iresd;

	iresd = *ires;
	while (file[i])
	{
		res[iresd] = ft_strdup(file[i]);
		iresd++;
		i++;
	}
	*ires = iresd;
}

char	**format_file(char **file, int j, int ires, int jres)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * tab_size(file));
	if (!res)
		return (NULL);
	while (file[i] && !is_map_begin(file[i]))
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
			set_var(&i, &j, &jres);
	}
	print_
	fill_map(file, res, &ires, i);
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
	printf("BEFORE FOMRAT\n");
	print_file(file);
	file = format_file(file, 0, 0 , 0);
	printf("AFTER FORMAT\n");
	print_file(file);
	return (file);
}

int	check_file(char *path)
{
	char **file;

	file = fill_file(path);
	(void)file;
	if (!check_elem(file))
		return (0);
	if (!check_map(file))
		return (0);
	return (1);
}