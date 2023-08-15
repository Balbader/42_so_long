/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 07:42:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/07 07:42:50 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(t_map *map)
{
	ft_printf("[ " RED"!!"RESET " ] | " \
			RED"%s"RESET" is not a valid map.\n", map->map_path);
	ft_free_tab(map->grid);
	free(map->map_path);
	exit(EXIT_FAILURE);
}
