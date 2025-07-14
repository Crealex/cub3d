/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:52 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/14 11:26:45 by psoulie          ###   ########.fr       */
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
# include <cub3d2.h>

// keycodes
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RIGHT 65363
# define LEFT 65361
# define SPACE 32

// macros
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define MOVE_SPD 1.7
# define TURN_SPD 0.03
# define FOV 1.0455
# define MINIMAP_SIZE 7
# define TILE_SIZE 25

typedef struct s_minimap
{
	int		len_x;
	int		len_y;
	int		cx;
	int		cy;
	int		ix;
	int		iy;
	int		mx;
	int		my;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
	char	**map;
	void	*img;
}				t_minimap;

typedef struct s_background
{
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
	void	*img;
	float	cos_a;
	float	sin_a;
}				t_background;

typedef struct s_square
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
	int		sx;
	int		sy;
	void	*img;
	int		bpp;
	int		line_size;
	int		endian;
	char	*addr;
}				t_player;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	int				winsize_x;
	int				winsize_y;
	int				tilesize;
	t_player		*player;
	t_minimap		*mapi;
	t_background	*background;
	t_map			*map;
	t_texture		*textures;
}				t_data;

// movement
void			player_move_forwards(t_data *data);
void			player_move_right(t_data *data);
void			player_move_left(t_data *data);
void			player_move_backwards(t_data *data);
int				loop(t_data *data);

// collision
int				forward_collision(t_data *data, t_player *player);
int				h_forward_collision(t_data *data, t_player *player);
int				v_forward_collision(t_data *data, t_player *player);

// rotation
void			player_rotate_left(t_data *data);
void			player_rotate_right(t_data *data);

// doors
void			check_door(t_data *data);

// window init
void			refresh_window(t_data *data);
t_data			*data_init(t_minimap *mapi, t_map *map);
t_background	*background_init(t_data *data);

// controls init
void			set_hooks(t_data *data);
int				on_keypress(int keycode, t_data *data);
int				on_keyrelease(int keycode, t_data *data);

// map init
void			find_player_pos(t_data *data, t_player *square, t_map *mapi);
void			map_init(t_data *data, t_player *player, t_minimap *mapi);
int				is_empty(char c);

// player init
void			compute_square(t_data *data, t_player *square);
void			clear_square(t_data *data, t_player *square);
void			dup_square(t_data *data);
t_player		*square_init(t_data *data);

// ray casting
void			show_rays(t_data *data, t_player *player);
void			base_bg(t_data *data);
void			place_wall(t_data *data, t_hit hit, int x);

// end
int				proper_exit(t_data *data);

// utils
char			**tab_dup(char **tab);
int				tab_width(char **tab);
int				ftt_strlen(char *str);
int				is_door_or_wall(char c);

// DDA de alex le big boos qui est Karim
void			ray_cast(t_player *player, t_map *map, double off, t_hit *hit);
double			ft_abs(double n);
int				define_step(double n);
char			define_side_hit(double angle, int side);
void			fill_data(t_dda *data, t_player *player, double offset);

// handle_door DDA
void			handle_door(t_map *map, t_dda *data, t_hit *hit);
int				hit_door(t_map *map, t_dda *data);

// texture de alex le big boos qui est Karim
unsigned int	define_pix_texture(t_hit hit, t_data *data, t_img *tex);
t_texture		*textures_init(t_data *data);
t_img			*define_tex(t_hit hit, t_data *data);
void			free_img(t_img *img, t_data *data);
t_img			*display_anim_open(t_data *data);
t_img			*display_anim_close(t_data *data);
void			anim_door(t_data *data, t_hit hit, int x);
void			handle_timer(t_data *data);
void			free_tex(t_texture *tex, t_data *data);
void			put_pixel(t_data *data, int x, int y, unsigned int color);
int				define_tex_x(t_hit hit, t_img *tex);
double			find_wall_size(t_data *data, double dist);

#endif
