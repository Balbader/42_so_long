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

void	ft_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

void	ft_render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data->mlx, data->win, j++, i, color);
		++i;
	}
}

int	ft_render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	ft_render(t_data *data)
{
	// ft_render_background(data, WHITE_PIXEL);
	ft_render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	ft_render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
		100, 100, GREEN_PIXEL});
	return (0);
}


int	main(void)
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

// int	main(void)
// {
// 	t_data	img_1;
// 	t_data	mlx;
// 	t_data	win;

// 	mlx.mlx = mlx_init();
// 	if (!mlx.mlx)
// 		return (MLX_ERROR);
// 	win.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH,
// 	WINDOW_HEIGHT, "42 So_Long");
// 	if (!win.win)
// 	{
// 		free(win.win);
// 		return (MLX_ERROR);
// 	}
// 	img_1.img = mlx_new_image(mlx.mlx, IMG_WIDTH, IMG_HEIGHT);
// 	img_1.addr = mlx_get_data_addr(img_1.img,
// 	&img_1.bits_per_pixel, &img_1.line_length,
// 			&img_1.endian);
// 	ft_mlx_put_pixel(&img_1, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx.mlx, win.win, img_1.img, 0, 0);
// 	mlx_loop(mlx.mlx);
// 	mlx_destroy_image(mlx.mlx, img_1.img);
// 	mlx_destroy_window(mlx.mlx, win.win);
// 	mlx_destroy_display(mlx.mlx);
// 	free(mlx.mlx);
// 	return (0);
// }
