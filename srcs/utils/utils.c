/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:28:26 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/12 18:19:46 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**tab_dup(char **tab)
{
	int		i;
	char	**new_tab;

	i = 0;
	while (tab[i])
		i++;
	i++;
	new_tab = ft_calloc(sizeof(char *), i);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

int	tab_width(char **tab)
{
	int	i;
	int	len;
	int	max_len;

	i = 0;
	max_len = 0;
	len = 0;
	while (tab[i])
	{
		len = ft_strlen(tab[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

int	is_door_or_wall(char c)
{
	if (c == 'C' || c == 'O' || c == '1')
		return (1);
	return (0);
}
