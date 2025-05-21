/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:52 by psoulie           #+#    #+#             */
/*   Updated: 2025/05/21 19:54:36 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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
	int		w;
	int		a;
	int		s;
	int		d;
	void	*img;
}				t_player;

typedef struct	s_data
{
	void		*mlx;
	void		*window;
	int			winsize_x;
	int			winsize_y;
	void		*background;
	t_player	*player;
}				t_data;

// movement
void	player_move_forwards(t_data *data);
void	player_move_right(t_data *data);
void	player_move_left(t_data *data);
void	player_move_backwards(t_data *data);
int		loop(t_data *data);

// window init
t_data	*data_init();
void	refresh_window(t_data *data);

// controls init
void	set_hooks(t_data *data);
int 	on_keypress(int keycode, t_data *data);
int		on_keyrelease(int keycode, t_data *data);

// ray casting

#endif
