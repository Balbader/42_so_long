/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 07:58:37 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/07 07:58:38 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_win(t_vars *vars)
{
	vars->win_width = vars->map.width * TILE_SIZE ;
	vars->win_height = vars->map.height * TILE_SIZE;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, \
				vars->win_width, vars->win_height, "so_long");
	if (!vars->win)
		exit(1);
	vars->final_image.img = mlx_new_image(vars->mlx, \
							vars->win_width, vars->win_height);
	vars->final_image.addr = mlx_get_data_addr(vars->final_image.img, \
	&vars->final_image.bpp, &vars->final_image.line_len, \
	&vars->final_image.endian);
	vars->player.pos = ft_find_pos(vars->map.grid, MAP_START);
}
