/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 07:58:20 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/07 07:58:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if ac == 2 && if file is ".ber" */
bool	ft_check_main_args(int ac, char **av)
{
	if (ac != 2)
	{
		(void)av;
		ft_printf("[ "RED"!!"RESET" ] | Wrong arguments number" \
				RED" <./so_long path/to/map.ber>\n"RESET);
		return (false);
	}
	if (ft_check_file_extension(av[1]) != true)
	{
		ft_printf("[ "RED"!!"RESET" ] | "RED"%s"RESET \
				" is not a valid map.\n", av[1]);
		return (false);
	}
	return (true);
}
