/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_confirm_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:09:58 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:09:59 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_confirm_move(t_vars *vars)
{
	if (vars->player.move.up == true)
	{
		move(&(vars->map), &(vars->player), 0, -1);
		vars->player.move.up = 0;
	}
	if (vars->player.move.down == true)
	{
		move(&(vars->map), &(vars->player), 0, 1);
		vars->player.move.down = 0;
	}
	if (vars->player.move.left == true)
	{
		move(&(vars->map), &(vars->player), -1, 0);
		vars->player.move.left = 0;
	}
	if (vars->player.move.right == true)
	{
		move(&(vars->map), &(vars->player), 1, 0);
		vars->player.move.right = 0;
	}
}
