#include "so_long.h"

t_pos	ft_find_pos(char **map, char stuff)
{
	t_pos	point;

	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == stuff)
				return ((t_pos){point.x, point.y});
			point.x++;
		}
		point.y++;
	}
	return ((t_pos){0, 0});
}
