#include "gui.h"

void	top_line_redraw(t_gui *gui)
{
	int		x;

	x = -1;
	while (++x < gui->map_w)
		mlx_put_image_to_window(gui->mlx, gui->mlx->win_list,
			(gui->el[wall]->img_list)[0], x * 32, 0);
}

int	background_redraw(t_gui *gui)
{
	int		x;
	int		y;
	t_els	*up;

	x = -1;
	y = -1;
	while (++y < gui->map_h)
	{
		while (++x % (gui->map_w + 1) < gui->map_w)
		{
			up = gui->el[map2typ(gui->map[y][x % (gui->map_w + 1)])];
			while (up)
			{
				mlx_put_image_to_window(gui->mlx, gui->mlx->win_list,
					(up->img_list)[up->img], x % (gui->map_w + 1) * 32,
					y * 32);
				up = up->next;
			}
		}
	}
	mlx_put_image_to_window(gui->mlx, gui->mlx->win_list,
		(gui->el[player]->img_list)[gui->el[player]->img],
		gui->el[player]->x, gui->el[player]->y);
	gui->to_update = 1;
	return (0);
}

void	tile_redraw(t_gui *gui, int x, int y)
{
	t_els	*up;

	up = gui->el[map2typ(gui->map[y][x])];
	mlx_put_image_to_window(gui->mlx, gui->mlx->win_list,
		(up->img_list)[up->img], x * 32, y * 32);
}

void	point_draw(t_gui *gui, int x, int y, int size)
{
	int		i;
	int		width;

	i = -1;
	width = (2 * size) + 1;
	while (++i < width * width)
		mlx_pixel_put(gui->mlx, gui->mlx->win_list,
			x + (i % width) - size, y + (i / width) - size, 0xFFFFFF);
}

void	enemies_redraw(t_gui *gui)
{
	t_els	*en;

	en = gui->el[enemy];
	while (en)
	{
		if ((en->x != gui->player->x || en->y != gui->player->y)
			&& (en->img != en->img_list_size - 1
				|| map2typ(gui->map[en->y / 32][en->x / 32]) == background))
			mlx_put_image_to_window(gui->mlx, gui->mlx->win_list,
				(en->img_list)[en->img], en->x, en->y);
		else if (en->x != gui->player->x || en->y != gui->player->y)
			tile_redraw(gui, en->x / 32, en->y / 32);
		en = en->next;
	}
}
