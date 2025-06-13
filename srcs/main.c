
#include <cub3d.h>

int main(int argc, char **argv)
{
	t_map *map;
	t_player player;

	map = parsing(argc, argv);
	player.posx = 3.5;
	player.posy = 3.5;
	player.angle = 0;
	//printf("%s\n", map->matrix[3]);
	//printf("Ray at 0deg: %f\n", ray_cast(&player, map));
	if (!map)
		return (1);
	free_struct(map);
	return (0);
}

