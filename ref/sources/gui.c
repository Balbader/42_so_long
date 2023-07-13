/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:28:28 by emis              #+#    #+#             */
/*   Updated: 2023/01/18 20:42:11 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

t_gui	*new_gui(char *map_path)
{
	t_gui	*gui;

	gui = malloc(sizeof(t_gui));
	if (!gui)
		return (err(malloc_error), NULL);
	gui->mlx = mlx_init();
	gui->map = NULL;
	gui->el = NULL;
	if (gui->mlx && (new_map(gui, map_path) || el_init(gui)
			|| (BONUS && enemies(gui))))
	{
		gui_kill(gui);
		return (NULL);
	}
	if (!gui->mlx || !mlx_new_window(gui->mlx,
			gui->map_w * 32, gui->map_h * 32, TITLE))
	{
		gui_kill(gui);
		err(mlx_error);
		return (NULL);
	}
	gui->to_update = 1;
	gui->to_collect = count(gui->map, gui->map_h,
			gui->map_w, collectible);
	return (gui);
}

int	gui_refresh(t_gui *gui)
{
	if (gui->to_update)
	{
		mlx_put_image_to_window(gui->mlx, gui->mlx->win_list,
			(gui->el[player]->img_list)[gui->el[player]->img],
			gui->el[player]->x, gui->el[player]->y);
		if (BONUS && gui->to_update != 2)
			msg_move(gui, -1);
		else if (gui->to_update == 2)
			msg_move(gui, gui->mlx->end_loop);
	}
	if (BONUS && enemies_time_crush(gui))
		enemies_redraw(gui);
	gui->to_update = 0;
	return (0);
}

static int	destroy_el(t_gui *gui)
{
	int		img;
	t_els	*cur;
	t_els	*nxt;
	int		i;

	i = -1;
	while (++i < enemy + BONUS)
	{
		cur = gui->el[i];
		while (cur)
		{
			nxt = cur->next;
			img = -1;
			while (++img < cur->img_list_size)
				if (cur->img_list[img])
					mlx_destroy_image(gui->mlx, cur->img_list[img]);
			free(cur->img_list);
			free(cur);
			cur = nxt;
		}
	}
	free(gui->el);
	return (0);
}

int	gui_kill(t_gui *gui)
{
	if (gui->map)
		destroy_map(gui->map, gui->map_h);
	if (gui->el)
		destroy_el(gui);
	if (gui->mlx)
	{
		if (gui->mlx->win_list)
			mlx_destroy_window(gui->mlx, gui->mlx->win_list);
		mlx_destroy_display(gui->mlx);
		free(gui->mlx);
	}
	free(gui);
	err(-err(nb_error));
	return (0);
}
