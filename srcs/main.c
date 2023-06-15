/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:02:24 by baalbade          #+#    #+#             */
/*   Updated: 2023/05/01 14:02:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "42 So_Long");
	if (!data.win)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx, &ft_render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &ft_handle_keypress, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
