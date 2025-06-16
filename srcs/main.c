/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:15:39 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/16 14:33:28 by psoulie          ###   ########.fr       */
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
	// free_tab(data->mapi->map);
	free(data->mapi->map);
	mlx_destroy_image(data->mlx, data->mapi->img);
	free(data->mapi);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
	return (0);
}

t_minimap	*create_map()
{
	t_minimap	*mapi;

	mapi = malloc(sizeof(t_minimap));
	mapi->map = (char **)malloc(8 * sizeof(char *));
	mapi->map[7] = NULL;
	mapi->map[0] = "1111111111111";
	mapi->map[1] = "1000000001001";
	mapi->map[2] = "1111001101001";
	mapi->map[3] = "1111001111101";
	mapi->map[4] = "1100000001101";
	mapi->map[5] = "11E0000000001";
	mapi->map[6] = "1111111111111";
	return (mapi);
}

int main()
{
	t_data	*data;
	t_minimap	*mapi;

	mapi = create_map();
	data = data_init(mapi);
	set_hooks(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (0);
}
