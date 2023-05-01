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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (MLX_ERROR);
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "42 So_Long");
	if (!win)
	{
		free(win);
		return (MLX_ERROR);
	}
	while (1)
		;
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
