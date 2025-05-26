/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:36:59 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/26 16:20:09 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab || !tab[i])
		return ;
	while (tab[i])
	{
		//printf("tab[%d]: %s\n", i, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}