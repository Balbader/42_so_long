/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:50:11 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 10:50:13 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	fill(int y, int x, t_map *map)
{
	if (x >= (int)map->width || y >= (int)map->height || x < 0 || y < 0)
		return (false);
	if (map->grid[y][x] == EMPTY_SPACE)
	{
		map->grid[y][x] = WALL;
		return (true);
	}
	if (map->grid[y][x] == COLLECTIBLE)
	{
		++map->flood.collectibles_collected;
		map->grid[y][x] = WALL;
		return (true);
	}
	if (map->grid[y][x] == MAP_EXIT)
		map->flood.exit_reached = true;
	return (false);
}

void	ft_flood_fill(int y, int x, t_map *map)
{
	if (fill(y, x - 1, map))
		ft_flood_fill(y, x - 1, map);
	if (fill(y, x + 1, map))
		ft_flood_fill(y, x + 1, map);
	if (fill(y - 1, x, map))
		ft_flood_fill(y - 1, x, map);
	if (fill(y + 1, x, map))
		flood(y + 1, x, map);
}
