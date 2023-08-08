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
	ft_copy_img(vars->map.empty_space, pos, &vars->final_image);
	if (c == WALL)
		ft_copy_img(vars->map.wall, pos, &vars->final_image);
	else if (c == COLLECTIBLE)
		ft_copy_img(vars->map.collectible, pos, &vars->final_image);
	else if (c == MAP_EXIT)
		ft_copy_img(vars->map.map_exit, pos, &vars->final_image);
	else if (c == MAP_START)
		ft_copy_img(vars->map.empty_space, pos, &vars->final_image);
	else if (c == PC_UP)
		ft_copy_img(vars->map.pc_up, pos, &vars->final_image);
	else if (c == PC_DOWN)
		ft_copy_img(vars->map.pc_down, pos, &vars->final_image);
	else if (c == PC_LEFT)
		ft_copy_img(vars->map.pc_left, pos, &vars->final_image);
	else if (c == PC_RIGHT)
		ft_copy_img(vars->map.pc_right, pos, &vars->final_image);
}
