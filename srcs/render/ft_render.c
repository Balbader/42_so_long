/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:11:06 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:11:07 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render(t_vars *vars)
{
	if (vars->win == NULL)
		return (MLX_ERROR);
	ft_render_map(vars);
	ft_confirm_move(vars);
	ft_render_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->final_image.img, 0, 0);
	/*
	ft_print_collectibles(vars, (t_pos){10, 20}, vars->map.collectible_count, \
	vars->player.collectible_count);
	ft_print_moves(vars, (t_pos){10, 40}, vars->player.move_count);
	*/
	return (EXIT_SUCCESS);
}
