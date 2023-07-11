/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:12:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:12:45 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_image(t_data *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "./rsrc/floor_texture.xpm";
	data->img.wall = "./rsrc/tree_texture.xpm";
	data->img.collect = "./rsrc/collect.xpm";
	data->img.player = "./rsrc/mario_player.xpm";
	data->img.exit = "./rsrc/exit_texture.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}
