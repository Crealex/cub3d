/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:28:26 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/30 10:46:42 by psoulie          ###   ########.fr       */
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

int	ftt_strlen(char *str)
{
	int	i;

	while (str && str[i])
		i++;
	return (i);
}