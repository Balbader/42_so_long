/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:49:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 16:49:41 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_vars	vars;

	if (ft_check_args(ac, av) != true)
		return (EXIT_FAILURE);
	ft_parse_map(av[1], &vars.map);
	if (validate_map(&vars) != true)
		map_error(&vars.map);
	ft_printf("[ "GREEN"OK"RESET" ] | %s" \
	" is a valid map!\n", av[1]);
	ft_init_win(&vars);
	ft_init_textures(&vars);
	ft_printf("[ "BLUE"GO"RESET" ] |" \
	" Your mission is to get all the ducks and exit the map.\n");
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_key, &vars);
	mlx_hook(vars.win, DestroyNotify, KeyPressMask, &close_window, &vars);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_loop(vars.mlx);
	ft_free_tab(vars.map.grid);
	ft_free_tabs(2, vars.map.map_path, vars.mlx);
}
