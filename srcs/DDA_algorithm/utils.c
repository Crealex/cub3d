/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:04:06 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/12 18:49:14 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

double	ft_abs(double n)
{
	if (n >= 0)
		return (n);
	return (n * -1.0);
}

int	define_step(double n)
{
	if (n < 0)
		return (-1);
	return (1);
}

void	fill_data(t_dda *data, t_player *player, double offset)
{
	data->player = player;
	data->offset = offset;
}
