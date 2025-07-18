/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:15:39 by psoulie           #+#    #+#             */
/*   Updated: 2025/07/14 10:32:56 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	proper_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player->img);
	free(data->player);
	mlx_destroy_image(data->mlx, data->background->img);
	free(data->background);
	free_double_tab(data->mapi->map);
	mlx_destroy_image(data->mlx, data->mapi->img);
	free(data->mapi);
	free_tex(data->textures, data);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_struct(data->map);
	free(data);
	exit(0);
	return (0);
}

t_minimap	*create_map(t_map *map)
{
	t_minimap	*mapi;

	mapi = ft_calloc(sizeof(t_minimap), 1);
	mapi->map = tab_dup(map->matrix);
	return (mapi);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_minimap	*mapi;
	t_map		*map;

	map = parsing(argc, argv);
	if (!map)
		return (1);
	mapi = create_map(map);
	data = data_init(mapi, map);
	set_hooks(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (0);
}
