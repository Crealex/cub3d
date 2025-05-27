/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:25:09 by atomasi           #+#    #+#             */
/*   Updated: 2025/05/27 17:23:32 by atomasi          ###   ########.fr       */
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

// *** UTILS ***

void	free_double_tab(char **tab);

// *** PARSING ***
t_map	*parsing(int argc, char **argv);
void	init_elem(t_elem *elem);
void	cpy_elem(t_elem src, t_elem *dst);
int		check_file(char *path);
int		check_elem(char **file);
int		count_line(int fd);
t_elem	check_texture_path(char *file, t_elem base);
int		check_map(char **file);
int		is_map_begin(char *line);
int		tab_size(char **file);
int		len_wspace(char *str);
int		is_dir(char c);

// *** TESTING FCT ***
void print_file(char **file);


#endif
