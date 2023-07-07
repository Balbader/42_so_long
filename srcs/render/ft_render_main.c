/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:11:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:11:16 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_main(t_data *data)
{
	// data->width = 10;
	// data->height = 10;
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width), (data->height * data->img.height),
			"42 So_Long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &ft_render, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &ft_key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &ft_end_game, data);
	mlx_loop(data->mlx_ptr);
	ft_end_game(data);
}
