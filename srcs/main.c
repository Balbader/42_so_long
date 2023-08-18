/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:50:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/08 14:50:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_vars	vars;

	if (ft_check_main_args(ac, av) != true)
		return (EXIT_FAILURE);
	ft_parse_map(av[1], &vars.map);
	if (ft_validate_map(&vars) != true)
		ft_map_error(&vars.map);
	ft_printf("[ "GREEN"OK"RESET" ] | %s" \
		" is a valid map!\n", av[1]);
	ft_init_win(&vars);
	ft_init_textures(&vars);
	ft_printf("[ "BLUE"GO"RESET" ] |" \
		" Your mission is to get all the bones and exit the map.\n");
	mlx_hook(vars.win, KeyPress, KeyPressMask, &ft_handle_key, &vars);
	mlx_hook(vars.win, DestroyNotify, KeyPressMask, &ft_close_window, &vars);
	mlx_loop_hook(vars.mlx, &ft_render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
