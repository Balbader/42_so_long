/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:29:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/05 08:29:04 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_pc_up(t_vars *vars)
{
	vars->map.pc_up = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/PC_UP.xpm");
}

void	ft_set_pc_down(t_vars *vars)
{
	vars->map.pc_down = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/PC_DOWN.xpm");
}

void	ft_set_pc_left(t_vars *vars)
{
	vars->map.pc_left = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/PC_LEFT.xpm");
}

void	ft_set_pc_right(t_vars *vars)
{
	vars->map.pc_right = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/PC_RIGHT.xpm");
}

void	ft_set_player(t_vars *vars)
{
	vars->player.img = ft_load_texture_to_img(vars, \
	"assets/textures/PLAYER/XPM/NORMAL/1.xpm");
}
