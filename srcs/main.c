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
	t_data	img;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (MLX_ERROR);
	img.img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "42 So_Long");
	if (!win)
	{
		free(win);
		return (MLX_ERROR);
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	free(win);
	return (0);
}
