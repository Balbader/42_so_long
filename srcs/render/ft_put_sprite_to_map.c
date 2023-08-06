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
	copy_image(vars->map.empty_space, pos, &vars->final_image);
	if (c == WALL)
		copy_image(vars->map.wall, pos, &vars->final_image);
	else if (c == COLLECTIBLE)
		copy_image(vars->map.collectible, pos, &vars->final_image);
	else if (c == MAP_EXIT)
		copy_image(vars->map.map_exit, pos, &vars->final_image);
	else if (c == MAP_START)
		copy_image(vars->map.empty_space, pos, &vars->final_image);
	else if (c == PC_UP)
		copy_image(vars->map.pc_up, pos, &vars->final_image);
	else if (c == PC_DOWN)
		copy_image(vars->map.pc_down, pos, &vars->final_image);
	else if (c == PC_LEFT)
		copy_image(vars->map.pc_left, pos, &vars->final_image);
	else if (c == PC_RIGHT)
		copy_image(vars->map.pc_right, pos, &vars->final_image);
}
