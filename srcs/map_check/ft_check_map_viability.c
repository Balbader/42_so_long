/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_viability.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:48:18 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/13 11:48:20 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Check if there is only 1 exit && 1 player
 * checks if there is other symbols than the ones allowed
*/

int	ft_check_map_viability(char *map_line, t_content *content)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			ft_print_error("Error.\nPlease verify number of player or exit.\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->space)
		{
			ft_print_error("Error.\nUnknown symbol(s) in '.ber' file.\n");
			return (0);
		}
		i++;
	}
	return (1);
}
