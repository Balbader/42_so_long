/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:10:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:10:44 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_moves(t_vars	*vars, t_pos pos, int steps)
{
	char	*new_str;
	char	*steps_str;

	steps_str = ft_itoa(steps);
	new_str = ft_strjoin("Steps: ", steps_str);
	mlx_string_put(vars->mlx, vars->win, pos.x, pos.y, BLACK_PIXEL, new_str);
	ft_free_tabs(2, steps_str, new_str);
}
