/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:38:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/15 11:38:19 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_floor(t_vars *vars)
{
	vars->map.floor = ft_load_texture_to_img(vars, \
	"assets/sprites/grass.xpm");
}
