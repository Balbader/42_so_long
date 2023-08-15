/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:46:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 11:46:04 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_validate_content(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (!ft_count_content(map, map->grid[y][x]))
				return (false);
			x++;
		}
		y++;
	}
	return (map->wall_count > 0 && map->pc_count > 0 \
			&& map->collectible_count > 0 && map->floor_count > 0 && \
			map->map_exit_count == 1 && map->map_start_count == 1);
}
