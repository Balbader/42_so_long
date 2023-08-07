/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 07:42:25 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/07 07:42:27 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
