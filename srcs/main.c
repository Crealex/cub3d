
#include <cub3d.h>

int main(int argc, char **argv)
{
	t_map *map;
	//t_player player;

	map = parsing(argc, argv);
	// player.posx = 2.48;
	// player.posy = 5.48;
	// player.angle = 6.86;
	//(void)player;
	//printf("%s\n", map->matrix[3]);
	//printf("Ray at %fdeg: %f\n", player.angle, ray_cast(&player, map));
	if (!map)
		return (1);
	free_struct(map);
	return (0);
}

