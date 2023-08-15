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
	ft_set_mid_wall(vars);
	ft_set_map_exit(vars);
	ft_set_floor(vars);
	ft_set_collectibles(vars);
	ft_set_player(vars);
}
