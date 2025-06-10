
#include <cub3d.h>

int main(int argc, char **argv)
{
	t_map *salut;

	salut = parsing(argc, argv);
	if (!salut)
		return (1);
	free_struct(salut);
	return (0);
}
