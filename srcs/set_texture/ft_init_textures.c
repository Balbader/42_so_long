/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:39:32 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/05 08:39:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_textures(t_vars *vars)
{

	ft_set_wall(vars);
	ft_set_pc_up(vars);
	ft_set_pc_down(vars);
	ft_set_pc_left(vars);
	ft_set_pc_right(vars);
	ft_set_map_exit(vars);
	ft_set_empty_space(vars); // rename to floor
	ft_set_collectibles(vars);
	ft_set_player(vars);
}
