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
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->player.img.img);
	mlx_destroy_image(vars->mlx, vars->map.wall.img);
	mlx_destroy_image(vars->mlx, vars->map.mid_wall.img);
	mlx_destroy_image(vars->mlx, vars->map.floor.img);
	mlx_destroy_image(vars->mlx, vars->map.map_exit.img);
	mlx_destroy_image(vars->mlx, vars->map.collectible.img);
	mlx_destroy_image(vars->mlx, vars->final_image.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free_tab(vars->map.grid);
	ft_free_tabs(2, vars->map.map_path, vars->mlx);
	exit (0);
}
