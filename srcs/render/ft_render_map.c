/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:11:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:11:17 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map(t_vars *vars)
{
	t_pos	pos;
	char	current_sprite;

	pos.y = 0;
	while ((size_t)pos.y < vars->map.height)
	{
		pos.x = 0;
		while ((size_t)pos.x < vars->map.width)
		{
			current_sprite = vars->map.grid[(int)pos.y][(int)pos.x];
			ft_put_sprite_to_map(vars, pos, current_sprite);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
}
