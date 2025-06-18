/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:15:39 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/18 15:14:23 by atomasi          ###   ########.fr       */
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

	mapi = malloc(sizeof(t_minimap));
	mapi->map = tab_dup(map->matrix);
	return (mapi);
}

#include <cub3d.h>

int main(int argc, char **argv)
{
	t_data		*data;
	t_minimap	*mapi;
	t_map 		*map;

	map = parsing(argc, argv);
	// player.posx = 2.48;
	// player.posy = 5.48;
	// player.angle = 6.86;
	//(void)player;
	//printf("%s\n", map->matrix[3]);
	//printf("Ray at %fdeg: %f\n", player.angle, ray_cast(&player, map));
	if (!map)
		return (1);
	mapi = create_map(map);
	data = data_init(mapi, map);
	set_hooks(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (0);
}

