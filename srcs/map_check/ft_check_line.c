/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:56:44 by baalbade          #+#    #+#             */
/*   Updated: 2023/06/28 14:56:53 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_line(char *map_line, char wall)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			ft_print_error("Error\nMap line not close\n");
			return (0);
		}
		i++;
	}
	return (1);
}
