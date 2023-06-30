/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:32:07 by emis              #+#    #+#             */
/*   Updated: 2023/01/19 13:23:47 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gui.h"
#include <time.h>

static void	enemy_move(t_gui *gui, t_els *en)
{
	int	ran;
	int	dir;
	int	xy[2];
	int	d[2];

	ran = clock() * rand() % 2;
	dir = 4 - (ran * 5);
	xy[0] = en->x;
	xy[1] = en->y;
	while (!((dir + 1) % 5) || enemy_at(gui, en->x + d[0], en->y + d[1], 1)
		|| map2typ(gui->map[(en->y + d[1]) / 32][(en->x + d[0]) / 32]) == wall)
	{
		if ((ran && ++dir == 4) || (!ran && --dir == -1))
			return ;
		d[0] = (dir % 2 == 1) * (1 - 2 * (dir / 2)) * 32;
		d[1] = (dir % 2 == 0) * (1 - 2 * (dir / 2)) * 32;
	}
	if (enemy_at(gui, xy[0] + d[0], xy[1] + d[1], 0))
		necromancy(gui);
	en->x += d[0];
	en->y += d[1];
	tile_redraw(gui, xy[0] / 32, xy[1] / 32);
	if (en->x == gui->player->x && en->y == gui->player->y)
		msg_event(gui, died_event);
}

static void	enemies_animate(t_gui *gui)
{
	t_els	*iter;

	iter = gui->el[enemy];
	while (iter)
	{
		if ((!iter->img && (clock() * rand() % 10) / 5)
			|| (iter->img && iter->img < iter->img_list_size - 2))
			iter->img = (iter->img + 1) % (iter->img_list_size - 2);
		if (((!iter->img && (clock() * rand() % 11)
					/ (9 - (4 * (distance(gui, iter->x, iter->y) > 500))))
				&& iter->img != iter->img_list_size - 1)
			|| (iter->img == iter->img_list_size - 2
				&& (clock() * rand() % 10) / 4))
			enemy_move(gui, iter);
		iter = iter->next;
	}
}

int	enemies_time_crush(t_gui *gui)
{
	static clock_t	lastchng;
	clock_t			current;

	current = clock();
	if (!lastchng)
		lastchng = current;
	if ((double)(current - lastchng) / (double)CLOCKS_PER_SEC > 0.135)
	{
		enemies_animate(gui);
		lastchng = current;
		return (1);
	}
	return (0);
}

int	slash(t_gui *gui)
{
	t_els	*targ;
	int		dx;
	int		dy;
	int		xy;

	dx = (gui->player->img % 2 == 1) * (1 - 2 * (gui->player->img / 2)) * 32;
	dy = (gui->player->img % 2 == 0) * (1 - 2 * (gui->player->img / 2)) * 32;
	targ = enemy_at(gui, gui->player->x + dx, gui->player->y + dy, 1);
	if (!targ)
		return (0);
	xy = -1;
	while (++xy < 16 * 16)
	{
		if (abs(8 - (xy % 16)) == abs(8 - (xy / 16)))
			point_draw(gui, gui->player->x + dx + 8 + (xy % 16),
				gui->player->y + dy + 8 + (xy / 16), 1);
	}
	if (targ->img == targ->img_list_size - 2)
		msg_event(gui, boss_slain_event);
	else
		msg_event(gui, enemy_slain_event);
	targ->img = targ->img_list_size - 1;
	return (1);
}
