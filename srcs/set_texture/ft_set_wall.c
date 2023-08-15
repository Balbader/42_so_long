/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:39:05 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/15 11:39:07 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_wall(t_vars *vars)
{
	vars->map.wall = ft_load_texture_to_img(vars, \
	"assets/sprites/baobab.xpm");
}
