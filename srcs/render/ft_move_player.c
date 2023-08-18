/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:10:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:10:27 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_player(t_map *map, t_player *player, int x, int y)
{
	if (ft_is_obstacle(map->grid[player->pos.y + y][player->pos.x + x])
		|| (map->grid[player->pos.y + y][player->pos.x + x] == MAP_EXIT
		&& map->collectible_count != player->collectible_count))
		return (0);
	if (map->grid[player->pos.y + y][player->pos.x + x] == COLLECTIBLE
		&& ++player->collectible_count)
		map->grid[player->pos.y + y][player->pos.x + x] = FLOOR;
	if (map->grid[player->pos.y + y][player->pos.x + x] == MAP_EXIT)
	{
		ft_printf("[ "GREEN"SUCCESS"RESET" ] | You finished the map!\n"
			"[ "GREEN"COLLECTIBLES"RESET" ] |" \
			" Total Bones collected: %d\n[ "GREEN"MOVES"RESET,
			player->collectible_count);
		ft_printf(" ] | Total steps: %d\n", ++player->move_count);
		return (1);
		exit(EXIT_SUCCESS);
	}
	player->pos.y += y;
	player->pos.x += x;
	player->move_count++;
	ft_printf("Count : %d\n", player->move_count);
	return (0);
}
