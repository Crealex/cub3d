/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:52 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/11 23:24:56 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include <X11/ap_keysym.h>

// keycodes
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RIGHT 65363
# define LEFT 65361


// macros
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define MOVE_SPD 1.2
# define TURN_SPD 0.02
# define FOV M_PI / 3

typedef struct	s_map
{
	int		len_x;
	int		len_y;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
	char	**map;
	void	*img;
}				t_map;

typedef struct	s_background
{
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
	void	*img;
}				t_background;

typedef struct	s_square
{
	int		tile;
	int		side;
	int		half;
	int		colour;
	double	angle;
	double	cos_a;
	double	sin_a;
	double	posx;
	double	posy;
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	void	*img;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
}				t_player;

typedef struct	s_data
{
	void		*mlx;
	void		*window;
	int			winsize_x;
	int			winsize_y;
	int			tilesize;
	t_player	*player;
	t_map		*mapi;
	t_background *background;
}				t_data;

// movement
void	player_move_forwards(t_data *data);
void	player_move_right(t_data *data);
void	player_move_left(t_data *data);
void	player_move_backwards(t_data *data);
int		loop(t_data *data);

// collision
int	forward_collision(t_data *data, t_player *player);
int	h_forward_collision(t_data *data, t_player *player);
int	v_forward_collision(t_data *data, t_player *player);

// rotation
void	player_rotate_left(t_data *data);
void	player_rotate_right(t_data *data);

// window init
void			refresh_window(t_data *data);
t_data			*data_init();
t_background	*background_init(t_data *data);

// controls init
void	set_hooks(t_data *data);
int 	on_keypress(int keycode, t_data *data);
int		on_keyrelease(int keycode, t_data *data);

// map init
void	find_player_pos(t_data *data, t_player *square, t_map *mapi);
void	map_init(t_data *data, t_map *mapi);

// player init
void		compute_square(t_data *data, t_player *square);
void		clear_square(t_data *data, t_player *square);
void		dup_square(t_data *data);
t_player	*square_init(t_data *data);

// ray casting
void	show_rays(t_data *data, t_player *player);
void	base_bg(t_data *data);
void	place_wall(t_data *data, double dist, double offset, double iter);

// end
int	proper_exit(t_data *data);

#endif
