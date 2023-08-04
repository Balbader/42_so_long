/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:48:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 11:48:44 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_count_content(t_map *map, char c)
{
	if (c == WALL)
		return (++map->wall_count);
	else if (c == PC_UP || c == PC_DOWN || c == PC_LEFT || c == PC_RIGHT)
		return (++map->pc_count);
	else if (c == COLLECTIBLE)
		return (++map->collectible_count);
	else if (c == EMPTY_SPACE)
		return (++map->empty_space_count);
	else if (c == MAP_EXIT)
		return (++map->map_exit_count);
	else if (c == MAP_START)
		return (++map->map_start_count);
	return (false);
}
