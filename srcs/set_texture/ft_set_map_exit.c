/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:03:52 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/15 12:03:54 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_map_exit(t_vars *vars)
{
	vars->map.map_exit = ft_load_texture_to_img(vars, \
	"assets/sprites/cavern.xpm");
}
