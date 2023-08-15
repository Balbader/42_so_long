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

void	ft_move_player(t_map *map, t_player *player, int x, int y)
{
	if (ft_is_obstacle(map->grid[player->pos.y + y][player->pos.x + x])
		|| (map->grid[player->pos.y + y][player->pos.x + x] == MAP_EXIT
		&& map->collectible_count != player->collectible_count))
		return ;

	if (map->grid[player->pos.y + y][player->pos.x + x] == COLLECTIBLE
		&& ++player->collectible_count)
		map->grid[player->pos.y + y][player->pos.x + x] = EMPTY_SPACE;

	if (map->grid[player->pos.y + y][player->pos.x + x] == MAP_EXIT)
	{
		ft_printf("[ "PURPLE"GG"RESET" ] | You finished the map!\n"
			"[ "PURPLE"GG"RESET" ] | Ducks collected: %d\n[ "PURPLE"GG"RESET,
			player->collectible_count);
		ft_printf(" ] | Total steps: %d\n", ++player->move_count);
		exit(EXIT_SUCCESS);
	}
	player->pos.y += y;
	player->pos.x += x;
	player->move_count++;
	ft_printf("Count : %d\n", player->move_count);
}
