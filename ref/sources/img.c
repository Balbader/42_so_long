/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:41:42 by emis              #+#    #+#             */
/*   Updated: 2023/01/18 19:54:13 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

static char	*img_path_finder(t_type type, int variant)
{
	char	*name;
	char	*tmp;

	name = ft_calloc(1, ft_strlen(PATH_TEXTURES) + 8);
	ft_strlcat(name, PATH_TEXTURES, ft_strlen(PATH_TEXTURES) + 8);
	if (!name)
		return (NULL);
	tmp = ft_itoa(type);
	if (tmp)
	{
		ft_strlcat(name, tmp, ft_strlen(PATH_TEXTURES) + 8);
		free(tmp);
	}
	else
		err(malloc_error);
	tmp = ft_itoa(variant);
	if (tmp)
	{
		ft_strlcat(name, tmp, ft_strlen(PATH_TEXTURES) + 8);
		free(tmp);
	}
	else
		err(malloc_error);
	ft_strlcat(name, ".xpm", ft_strlen(PATH_TEXTURES) + 8);
	return (name);
}

t_img	**img_list_from_type(t_gui *gui, t_type type, int size)
{
	t_img	**img_list;
	char	*path;
	int		var;
	int		w;
	int		h;

	img_list = malloc(sizeof(t_img *) * size);
	if (!img_list)
	{
		err(malloc_error);
		return (NULL);
	}
	var = -1;
	while (++var < size)
	{
		path = img_path_finder(type, var);
		img_list[var] = mlx_xpm_file_to_image(gui->mlx,
				path, &w, &h);
		free(path);
		if (!img_list[var])
			err(img_404_error);
	}
	return (img_list);
}

int	img_list_size_from_type(t_type type)
{
	if (type == player)
		return (4);
	else if (type == enemy)
		return (10);
	return (1);
}
