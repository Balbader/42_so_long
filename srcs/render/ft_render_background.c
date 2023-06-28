/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:03:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/06/28 17:04:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_background(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall)
				ft_print_img(data, data->img.img_wall, i, y);
			if (data->map[y][i] == data->content.space)
				ft_print_img(data, data->img.img_floor, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}
