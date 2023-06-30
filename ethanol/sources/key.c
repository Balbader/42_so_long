/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:38:14 by emis              #+#    #+#             */
/*   Updated: 2023/01/18 14:27:55 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	player_animate(int keycode, t_gui *gui)
{
	if (keycode == up)
		gui->player->img = 2;
	else if (keycode == down)
		gui->player->img = 0;
	else if (keycode == left)
		gui->player->img = 3;
	else if (keycode == right)
		gui->player->img = 1;
	else
		return ;
	gui->to_update = 1;
}

int	move(int keycode, t_gui *gui)
{
	int	x;
	int	y;

	x = gui->player->x / 32;
	y = gui->player->y / 32;
	player_animate(keycode, gui);
	if (keycode == up && check_move(up, gui))
		gui->player->y -= 32;
	else if (keycode == down && check_move(down, gui))
		gui->player->y += 32;
	else if (keycode == left && check_move(left, gui))
		gui->player->x -= 32;
	else if (keycode == right && check_move(right, gui))
		gui->player->x += 32;
	else if (BONUS && keycode == attack)
		slash(gui);
	else
		return (1);
	gui->to_update = 1 + (keycode != attack);
	tile_redraw(gui, x, y);
	return (0);
}

int	key_press(int keycode, t_gui *gui)
{
	if (keycode == XK_Escape)
		mlx_loop_end(gui->mlx);
	else
		move(keycode, gui);
	return (0);
}

int	key_rel(int keycode, t_gui *gui)
{
	if (keycode && gui->mlx)
		(void)keycode;
	return (0);
}
