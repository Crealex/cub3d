/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:25:09 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/21 15:33:41 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <colours.h>
# include <fcntl.h>
# include "../includes/libft/libft.h"


typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor[3];
	int		ceiling[3];
	char	**matrix;
}			t_map;

typedef struct s_elem
{
	int	no;
	int so;
	int we;
	int ea;
	int f;
	int c;
}			t_elem;

t_map	*parsing(int argc, char **argv);
void	init_elem(t_elem *elem);
void	cpy_elem(t_elem src, t_elem *dst);

#endif
