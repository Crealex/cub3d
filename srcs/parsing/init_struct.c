/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:24:26 by atomasi           #+#    #+#             */
/*   Updated: 2025/06/10 10:33:18 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_elem(t_elem *elem)
{
	elem->ea = 0;
	elem->no = 0;
	elem->so = 0;
	elem->we = 0;
	elem->f = 0;
	elem->c = 0;
}

void	cpy_elem(t_elem src, t_elem *dst)
{
	dst->ea = src.ea;
	dst->f = src.f;
	dst->c = src.c;
	dst->no = src.no;
	dst->so = src.so;
	dst->we = src.we;
}

void	init_map(t_map *map)
{
	map->ceiling = 0;
	map->floor = 0;
	map->ea_path = NULL;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->matrix = NULL;
}
