#include "so_long.h"

char	**ft_duplicate_map(t_map *map)
{
	char	**grid;
	size_t	index;

	grid = malloc((map->height + 1) * sizeof(char *));
	if (!grid)
		exit(EXIT_FAILURE);
	index = 0;
	while (index < map->height)
	{
		grid[index] = ft_strdup(map->grid[index]);
		if (!grid[index])
		{
			ft_free_tab(grid);
			exit (EXIT_FAILURE);
		}
		index++;
	}
	grid[index] = 0;
	return (grid);
}
