/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sprite_to_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:10:58 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:11:00 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_sprite_to_map(t_vars *vars, t_pos pos, char c)
{
	ft_copy_img(vars->map.floor, pos, &vars->final_image);
	if (c == WALL)
		ft_copy_img(vars->map.wall, pos, &vars->final_image);
	else if (c == COLLECTIBLE)
		ft_copy_img(vars->map.collectible, pos, &vars->final_image);
	else if (c == MAP_EXIT)
		ft_copy_img(vars->map.map_exit, pos, &vars->final_image);
	else if (c == MAP_START)
		ft_copy_img(vars->map.floor, pos, &vars->final_image);
	else if (c == MID_WALL)
		ft_copy_img(vars->map.mid_wall, pos, &vars->final_image);
}
