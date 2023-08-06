#include "so_long.h"

void	ft_map_error(t_map *map)
{
	ft_printf("[ " RED"!!"RESET " ] | " \
			RED"%s"RESET" is not a valid map.\n", map->map_path);
	ft_free_tab(map->grid);
	free(map->map_path);
	exit(EXIT_FAILURE);
}
