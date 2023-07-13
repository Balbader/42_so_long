/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:32:06 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/13 11:32:08 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Check that game boundries are wall and there is no openings wihtin the walls
*/

int	ft_check_walls(char *map_line, char wall)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			ft_print_error("Error.\nUnclosed Line.\n");
			return (0);
		}
		i++;
	}
	return (1);
}
