/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:49:33 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/08 13:49:36 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_validate_map(t_vars *vars)
{	
	ft_printf("[ "YELLOW".."RESET \
	" ] | Validating map...\n");
	ft_map_size(&(vars->map));
	if (ft_check_format(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" is not rectangular.\n", vars->map.map_path))
		return (false);
	if (ft_validate_content(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" content is unknown.\n", vars->map.map_path))
		return (false);
	if (ft_check_if_open(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" is not closed by walls.\n", vars->map.map_path) != 0)
		return (false);
	if (ft_check_path(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" has no valid path.\n", vars->map.map_path) != 0)
		return (false);
	return (true);
}
