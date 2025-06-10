
#include <cub3d.h>

int main(int argc, char **argv)
{
	t_map *map;

	map = parsing(argc, argv);
	if (!map)
		return (1);
	free_struct(map);
	return (0);
}
