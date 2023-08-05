/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures_utils1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:28:53 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/05 08:28:54 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_map_exit(t_vars *vars)
{
	vars->map.map_exit = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/STAIRS.xpm");
}

void	ft_set_empty_space(t_vars *vars)
{
	vars->map.empty_space = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/FLOOR.xpm");
}

void	ft_set_collectibles(t_vars *vars)
{
	vars->map.collectible = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/DUCK.xpm");
}

void	ft_set_wall(t_vars *vars)
{
	vars->map.wall = ft_load_texture_to_img(vars, \
	"assets/textures/XPM/WALL.xpm");
}
