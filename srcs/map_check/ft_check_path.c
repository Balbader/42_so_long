/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:30:16 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 11:30:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_check_path(t_map *map)
{
	static t_map	map_copy;
	t_pos			start_pos;

	map_copy = *map;
	map_copy.flood.exit_reached = false;
	map_copy.grid = ft_duplicate_map(map);
	start_pos = ft_find_pos(map_copy.grid, MAP_START);
	if (!map_copy.grid)
		return (false);
	ft_flood_fill(start_pos.y, start_pos.x, &map_copy);
	if (map->collectible_count != map_copy.flood.collectibles_collected)
	{
		ft_free_tab(map_copy.grid);
		return (false);
	}
	ft_free_tab(map_copy.grid);
	return (map_copy.flood.exit_reached);
}
