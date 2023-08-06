/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:10:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:10:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_copy_img(t_img img, t_pos pos, t_img *final_img)
{
	t_pos			point;
	unsigned int	color;

	color = 0;
	point.y = 0;
	while (point.y < TILE_SIZE)
	{
		point.x = 0;
		while (point.x < TILE_SIZE)
		{
			color = get_pixel(&img, point.x, point.y);
			if (color && color != 4278190080)
				put_pixel(final_img, (pos.x * TILE_SIZE) + point.x, \
				(pos.y * TILE_SIZE) + point.y, (int)color);
			point.x++;
		}
		point.y++;
	}
}
