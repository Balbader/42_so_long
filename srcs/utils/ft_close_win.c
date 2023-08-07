/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 07:42:05 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/07 07:42:08 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_vars *vars)
{
	ft_printf("[ " RED "XX" RESET " ] |" \
		" You exited the game before finishing :(\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
