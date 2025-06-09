/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:15:39 by psoulie           #+#    #+#             */
/*   Updated: 2025/06/09 19:28:38 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_map	*create_map()
{
	t_map	*mapi;

	mapi = malloc(sizeof(t_map));
	mapi->map = (char **)malloc(8 * sizeof(char *));
	for (int i = 0; i < 8; i++)
		mapi->map[i] = (char *)malloc(14 * sizeof(char));
	mapi->map[7] = NULL;
	mapi->map[0] = "   1111111111111";
	mapi->map[1] = "1000000001001";
	mapi->map[2] = "1111001101001";
	mapi->map[3] = "1111001111101";
	mapi->map[4] = "1100000001101";
	mapi->map[5] = "1100000000001";
	mapi->map[6] = "1111111111111";
	return (mapi);
}

int main()
{
	t_data	*data;
	t_map	*mapi;

	mapi = create_map();
	data = data_init(mapi);
	set_hooks(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (0);
}
