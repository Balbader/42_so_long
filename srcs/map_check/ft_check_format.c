/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:45:47 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 11:45:48 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_check_format(t_map *map)
{
	size_t	y;

	y = 0;
	if (!map || !map->grid || map->width == map->height)
		return (false);
	y = 0;
	while (y < map->height)
		if (map->width != ft_strlen(map->grid[y++]))
			return (false);
	return (true);
}
