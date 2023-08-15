/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:04:11 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/15 12:04:13 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_player(t_vars *vars)
{
	vars->player.img = ft_load_texture_to_img(vars, \
	"assets/sprites/dino.xpm");
}
