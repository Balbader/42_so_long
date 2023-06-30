/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   els.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:54:52 by emis              #+#    #+#             */
/*   Updated: 2023/01/17 17:51:27 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

t_els	*new_els(t_gui *gui, t_type type, int x, int y)
{
	t_els	*element;

	element = malloc(sizeof(t_els));
	if (!element)
	{
		err(malloc_error);
		return (NULL);
	}
	element->type = type;
	element->x = x;
	element->y = y;
	element->img = 0;
	element->img_list_size = img_list_size_from_type(type);
	element->img_list = img_list_from_type(gui, type, element->img_list_size);
	element->next = NULL;
	return (element);
}

int	add_els(t_els **els, t_els *to_add)
{
	t_els	*current;

	if (!to_add)
		return (err(element_error));
	current = *els;
	if (!current)
		*els = to_add;
	else
	{
		while (current->next)
			current = current->next;
		current->next = to_add;
	}
	return (err(nb_error));
}

int	count(char	**map, int h, int w, t_type type)
{
	int	nb;
	int	x;
	int	y;

	nb = 0;
	y = -1;
	x = -1;
	while (++y < h)
		while (++x % (w + 1) < w)
			if (map2typ(map[y][x % (w + 1)]) == type)
				nb++;
	return (nb);
}

int	el_init(t_gui *gui)
{
	int			itertype;
	static int	x;
	static int	y;

	itertype = -1;
	gui->el = ft_calloc(sizeof(t_els *), enemy + BONUS);
	if (!gui->el)
		return (err(malloc_error));
	while (++itertype < player && !err(nb_error))
		gui->el[itertype] = new_els(gui, itertype, 0, 0);
	while (++y < gui->map_h)
	{
		while (++x % (gui->map_w + 1) < gui->map_w)
		{
			if (map2typ(gui->map[y][x % (gui->map_w + 1)]) == player)
			{
				gui->el[player] = new_els(gui, player,
						(x % (gui->map_w + 1)) * 32, y * 32);
				gui->map[y][x % (gui->map_w + 1)] = '0';
			}
		}
	}
	gui->player = gui->el[player];
	return (err(nb_error));
}
