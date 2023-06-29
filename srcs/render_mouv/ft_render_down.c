/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:23:55 by baalbade          #+#    #+#             */
/*   Updated: 2023/06/28 17:24:03 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_down(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (ft_check_collectible(data) == 0)
			{
				ft_printf("Congratulations, you have won the game with a");
				ft_printf(" total count of %d moves !\n", data->count);
				ft_end_game(data);
			}
		}
	}
}
