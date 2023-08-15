/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mid_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:38:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/15 11:38:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_mid_wall(t_vars *vars)
{
	vars->map.mid_wall = ft_load_texture_to_img(vars, \
	"assets/sprites/baobab.xpm");
}
