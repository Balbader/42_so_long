/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_high.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:18:26 by emis              #+#    #+#             */
/*   Updated: 2023/01/18 15:13:50 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

int	main(int ac, char **av)
{
	t_gui	*gui;

	if (ac != 2)
		return (err(argument_error));
	gui = new_gui(av[1]);
	if (!gui)
		return (1);
	ft_printf("%s", CLR);
	background_redraw(gui);
	msg_event(gui, start_event);
	msg_move(gui, -2);
	mlx_loop_hook(gui->mlx, &gui_refresh, gui);
	mlx_hook(gui->mlx->win_list, KeyPress, KeyPressMask, &key_press, gui);
	mlx_hook(gui->mlx->win_list, KeyRelease, KeyReleaseMask, &key_rel, gui);
	mlx_hook(gui->mlx->win_list, DestroyNotify, 0L, &mlx_loop_end, gui->mlx);
	mlx_hook(gui->mlx->win_list, Expose, 0L, background_redraw, gui);
	mlx_loop(gui->mlx);
	if (!msg_event(gui, -1))
		msg_event(gui, exit_event);
	gui_kill(gui);
	return (err(nb_error) != 0);
}
