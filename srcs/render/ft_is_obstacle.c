/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_obstacle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:10:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:10:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_is_obstacle(char grid_value)
{
	return (grid_value == WALL || grid_value == PC_UP || \
			grid_value == PC_DOWN || grid_value == PC_LEFT || \
			grid_value == PC_RIGHT);
}
