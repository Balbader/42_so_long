#include "gui.h"

static int	propaganda(char **fillmap, int x, int y)
{
	int	filled;

	filled = 0;
	if (map2typ(fillmap[y - 1][x]) != wall
		&& fillmap[y - 1][x] != 42 && ++filled)
		fillmap[y - 1][x] = 42;
	if (map2typ(fillmap[y + 1][x]) != wall
		&& fillmap[y + 1][x] != 42 && ++filled)
		fillmap[y + 1][x] = 42;
	if (map2typ(fillmap[y][x - 1]) != wall
		&& fillmap[y][x - 1] != 42 && ++filled)
		fillmap[y][x - 1] = 42;
	if (map2typ(fillmap[y][x + 1]) != wall
		&& fillmap[y][x + 1] != 42 && ++filled)
		fillmap[y][x + 1] = 42;
	return (filled);
}

static char	**copy_map(char **map, int size)
{
	char	**cpy;
	int		i;

	cpy = ft_calloc(sizeof(char *), size);
	i = -1;
	while (++i < size)
		cpy[i] = ft_strdup(map[i]);
	return (cpy);
}

int	printmap(char **map_copy)
{
	int	i;
	int	j;

	i = -1;
	while (map_copy[++i])
	{
		j = -1;
		while (map_copy[i][++j])
			ft_printf("%c", map_copy[i][j]);
		ft_printf("\n");
	}
	ft_printf("\n");
	return (1);
}

int	check_map(t_gui *gui, int status)
{
	static char	**fillmap;
	int			filled;
	int			x;
	int			y;

	x = gui->map_w;
	y = gui->map_h;
	if (!status && (count(gui->map, y, x, collectible) < 1 || count(gui->map,
				y, x, player) != 1 || count(gui->map, y, x, map_exit) != 1))
		return (err(map_invalid_error));
	if (!fillmap)
		fillmap = copy_map(gui->map, gui->map_h);
	filled = status;
	x = 0;
	y = 0;
	while (++y < gui->map_h)
		while (++x % (gui->map_w + 1) < gui->map_w)
			if (map2typ(fillmap[y][x % (gui->map_w + 1)]) >= player)
				filled += propaganda(fillmap, x % (gui->map_w + 1), y);
	if (filled != status)
		return (check_map(gui, filled));
	if (count(fillmap, y, gui->map_w, collectible)
		|| count(fillmap, y, gui->map_w, map_exit))
		return (destroy_map(fillmap, gui->map_h), err(map_no_win_error));
	return (destroy_map(fillmap, gui->map_h), 0);
}

int	check_move(t_kbind key, t_gui *gui)
{
	int		xtarg;
	int		ytarg;
	int		ttarg;

	xtarg = (key == right) - (key == left);
	ytarg = (key == down) - (key == up);
	ttarg = gui->map[ytarg + (gui->player->y / 32)]
	[xtarg + (gui->player->x / 32)];
	if (map2typ(ttarg) == wall)
		return (0);
	else if (BONUS && enemy_at(gui, (xtarg * 32) + gui->player->x,
			(ytarg * 32) + gui->player->y, 1))
		msg_event(gui, died_event);
	else if (map2typ(ttarg) == collectible)
	{
		gui->to_collect--;
		msg_event(gui, collected_event);
		gui->map[ytarg + (gui->player->y / 32)]
		[xtarg + (gui->player->x / 32)] = '0';
	}
	else if (map2typ(ttarg) == map_exit)
		if (!gui->to_collect)
			msg_event(gui, win_event);
	return (1);
}
