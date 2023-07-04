/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:13:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:13:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_end_game(data);
	if (keysym == XK_w)
		ft_render_top(data);
	if (keysym == XK_d)
		ft_render_right(data);
	if (keysym == XK_a)
		ft_render_left(data);
	if (keysym == XK_s)
		ft_render_down(data);
	return (0);
}
