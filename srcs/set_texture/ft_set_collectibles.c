/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:38:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/15 11:38:07 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_collectibles(t_vars *vars)
{
	vars->map.collectible = ft_load_texture_to_img(vars, \
	"assets/sprites/collect.xpm");
}
