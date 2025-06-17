/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:28:26 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/17 11:39:50 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**tab_dup(char **tab)
{
	int		i;
	int		j;
	char	**new_tab;

	i = 0;
	while (tab[i])
		i++;
	i++;
	new_tab = malloc(i * sizeof(char *));
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}
