/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:49:49 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/08 13:49:51 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(t_map *map)
{
	size_t	x_size;
	size_t	y_size;

	x_size = 0;
	y_size = 0;
	if (!map || !map->grid)
		return ;
	x_size = ft_strlen(map->grid[0]);
	if (x_size == 0)
		return ;
	while (map->grid[y_size] != 0)
		y_size++;
	if (y_size == 0)
		return ;
	map->width = x_size;
	map->height = y_size;
}
