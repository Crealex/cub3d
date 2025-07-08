/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:25:09 by atomasi           #+#    #+#             */
/*   Updated: 2025/07/08 22:59:44 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D2_H

# define CUB3D2_H

# include <stdio.h>
# include <colours.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/libft/libft.h"

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor;
	int		ceiling;
	int		player_start;
	int		door_anim; // 0 static, 1 need animation
	double	timer;
	char	**matrix;
}			t_map;

typedef struct s_elem
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}			t_elem;

typedef struct s_dda
{
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	ray_dirx;
	double	ray_diry;
	double	perp_wall_dist;
	int		hit;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
}			t_dda;

typedef struct s_hit
{
	char	type;
	double		x;
	double		y;
	char	side;
	double	dist;
	double	ray_x;
	double	ray_y;
	int		tex_x;
	int		i;
	double	wall_size;
}			t_hit;

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*path;
	int		bpp; // bit per pixel
	int		line_size;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_texture
{
	t_img	*no;
	t_img	*so;
	t_img	*ea;
	t_img	*we;
	t_img	*door;
	t_img	*door_2;
	t_img	*door_3;
	t_img	*door_4;
}			t_texture;

// *** UTILS ***

void	free_double_tab(char **tab);
void	free_struct(t_map *map);
void	clean_exit(char **file, t_map *map);

// *** PARSING ***
t_map	*parsing(int argc, char **argv);
void	init_elem(t_elem *elem);
void	cpy_elem(t_elem src, t_elem *dst);
int		check_file(char **file);
int		is_two_spaces(int i, int j, char **file);
char	**fill_file(char *path);
int		check_elem(char **file);
int		count_line(int fd);
t_elem	check_texture_path(char *file, t_elem base);
int		check_map(char **file);
int		is_map_begin(char *line);
int		find_begin(char **file);
int		tab_size(char **file);
int		len_wspace(char *str);
int		is_dir(char c);
int		try_open(char *path);
void	init_map(t_map *map);
t_map	*fill_struct(char **file);
void	fill_matrix(t_map *map, char **file);
// *** TEXTURES ***
// *** TESTING FCT ***
void	print_struct(t_map *map);
void	print_file(char **file);
int		is_door(int i, char **file, int no);

#endif
