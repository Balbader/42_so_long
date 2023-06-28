/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:56:28 by baalbade          #+#    #+#             */
/*   Updated: 2023/06/28 14:56:37 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_format(char **map)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			ft_print_error("Error.\nExpected Format: Square or Rectangle\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
