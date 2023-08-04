/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:38:23 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 11:38:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parse_map(const char *path_to_map, t_map *map)
{
	int		fd;
	char	*text;

	fd = open(path_to_map, 0, O_RDONLY);
	if (fd == -1 && ft_printf("[ "RED"!!"RESET" ] | "RED"%s"RESET \
				" is not a valid map.\n", path_to_map) != 0)
		exit(EXIT_FAILURE);
	map->map_path = ft_strdup(path_to_map);
	if (!map->map_path)
	{
		free(map->map_path);
		return ;
	}
	text = read_map(fd);
	if (!text)
	{
		free(text);
		return ;
	}
	map->grid = ft_split(text, '\n');
	if (!map->grid[0])
		map_error(map);
	free(text);
	close(fd);
}
