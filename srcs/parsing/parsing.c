/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:19:00 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/20 17:44:24 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_map(char *path)
{
	// check si les 4 paths de texture sont valide
	// check si les couleurs pour le sol et le plafond sont valides
	// check si le map est bien fermée
	// check si le joueur est bien mis
	// check si le chemin de la map est valide
	return (0);
}

int check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		perror(RED"Error,\nOne argument is excepted!!\n"RESET);
		return (0);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		perror(RED"Error,\nInvalid path with a map!\n"RESET);
		return (0);
	}
	return (1);
}

t_map	*parsing(int argc, char **argv)
{
	t_map map;

	if (!check_args(argc, argv) || !check_map(argv[1]))
		return (NULL);
	return (NULL);
}
