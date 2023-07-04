/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:11:31 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:11:33 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_other(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				ft_print_img(data, data->img.img_collect, i, y);
			if (data->map[y][i] == data->content.player)
			{
				data->pos.x = i * data->img.width;
				data->pos.y = y * data->img.height;
				ft_print_img(data, data->img.img_player, i, y);
			}
			if (data->map[y][i] == data->content.exit)
				ft_print_img(data, data->img.img_exit, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}
