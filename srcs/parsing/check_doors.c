/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:39:27 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/18 15:06:54 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_adj(int i, char **file, int no, char or)
{
	if (or == 'h')
	{
		if (file[no][i + 1] != '1' || file[no][i - 1] != '1')
			return (0);
		if (file[no + 1][i] != '0' || file[no - 1][i] != '0')
			return (0);
		return (1);
	}
	else if (or == 'v')
	{
		if (file[no][i + 1] != '0' || file[no][i - 1] != '0')
			return (0);
		if (file[no + 1][i] != '1' || file[no - 1][i] != '1')
			return (0);
		return (1);
	}
	return (0);
}

static int	is_valid(int i, char **file, int no)
{
	if (file[no][i + 1] && file[no][i - 1] && file[no - 1] && file[no + 1]
			&& file[no - 1][i] && file[no + 1][i])
	{
		if (file[no][i + 1] == '1')
		{
			if (check_adj(i, file, no, 'h'))
				return (1);
		}
		else if (file[no][i + 1] == '0')
		{
			if (check_adj(i, file, no, 'v'))
				return (1);
		}
		return (0);
	}
	return (0);
}

int	is_door(int i, char **file, int no)
{
	printf("%c\n", file[no][i]);
	if (file[no][i] && file[no][i] != 'O' && file[no][i] != 'C')
		return (0);
	if (!is_valid(i, file, no))
		return (0);
	return (1);
}