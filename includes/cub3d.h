/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:52 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 14:20:35 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <X11/ap_keysym.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct	s_square
{
	int		side;
	int		colour;
	int		angle;
	int		posx;
	int		posy;
	void	*img;
}				t_square;

typedef struct	s_data
{
	void		*mlx;
	void		*window;
	t_square	*player;
}				t_data;

// movement
void	player_move_forwards(t_data *data);

// window init
t_data	*data_init();

// controls init
void	set_hooks(t_data *data);

// ray casting
void	test();

#endif
