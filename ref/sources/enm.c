#include "../includes/gui.h"
#include <time.h>

double	distance(t_gui *gui, int x, int y)
{
	return (hypot(abs(gui->player->x - x), abs(gui->player->y - y)));
}

t_els	*enemy_at(t_gui *gui, int x, int y, int a)
{
	t_els	*iter;

	iter = gui->el[enemy];
	while (iter)
	{
		if (iter->x == x && iter->y == y && (!a
				|| (a && iter->img != iter->img_list_size - 1)))
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

int	necromancy(t_gui *gui)
{
	t_els	*iter;

	iter = gui->el[enemy];
	while (iter && !err(nb_error))
	{
		if (iter->img == iter->img_list_size - 1
			&& ((clock() * rand()) % 100) / 95)
			iter->img = iter->img_list_size - 2;
		iter = iter->next;
	}
	return (0);
}

int	enemies(t_gui *gui)
{
	int	rate;
	int	i;

	gui->el[enemy] = NULL;
	rate = ((clock() * rand()) % 10) - (5 * (gui->map_h * gui->map_w > 500));
	i = -1;
	while (++i < gui->map_h * gui->map_w && !err(nb_error))
		if (map2typ(gui->map[i / gui->map_w][i % gui->map_w]) == background
			&& distance(gui, 32 * (i % gui->map_w), 32 * (i / gui->map_w)) > 75
			&& !enemy_at(gui, 32 * (i % gui->map_w), 32 * (i / gui->map_w), 0)
			&& (((clock() * rand()) % 100) + rate) / 95)
			add_els(&gui->el[enemy], new_els(gui, enemy,
					32 * (i % gui->map_w), 32 * (i / gui->map_w)));
	return (err(nb_error));
}
