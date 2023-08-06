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

/* Init MLX window */
void	ft_init_win(t_vars *vars)
{
	vars->win_width = vars->map.width * TILE_SIZE ;
	vars->win_height = vars->map.height * TILE_SIZE;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, \
				vars->win_width, vars->win_height, "so_long");
	if (!vars->win)
		exit(1);
	vars->final_image.img = mlx_new_image(vars->mlx, \
							vars->win_width, vars->win_height);
	vars->final_image.addr = mlx_get_data_addr(vars->final_image.img, \
	&vars->final_image.bpp, &vars->final_image.line_len, \
	&vars->final_image.endian);
	vars->player.pos = find_in_map(vars->map.grid, MAP_START);
}

/* returns true if '.ber' file */
bool	ft_check_file_extension(const char *path_to_map)
{
	size_t	len;

	len = ft_strlen(path_to_map);
	if (len < 5 || ft_strncmp(path_to_map + (len - 4), ".ber", 4) == 0)
		return (true);
	return (false);
}

/* Checks if ac == 2 && if file is ".ber" */
bool	ft_check_args(int ac, char **av)
{
	if (ac != 2)
	{
		(void)av;
		ft_printf("[ "RED"!!"RESET" ] | Wrong arguments number" \
				RED" <./so_long path/to/map.ber>\n"RESET);
		return (false);
	}
	if (ft_check_file_extension(av[1]) != true)
	{
		ft_printf("[ "RED"!!"RESET" ] | "RED"%s"RESET \
				" is not a valid map.\n", av[1]);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	static t_vars	vars;

	// 1. Check arguments
	if (ft_check_args(ac, av) != true)
		return (EXIT_FAILURE);

	// 2. read map if args check ok
	ft_parse_map(av[1], &vars.map);

	// 3. if map is validated
	if (validate_map(&vars) != true)
		map_error(&vars.map);
	ft_printf("[ "GREEN"OK"RESET" ] | %s" \
	" is a valid map!\n", av[1]);
	ft_init_win(&vars);
	ft_init_textures(&vars);
	ft_printf("[ "BLUE"GO"RESET" ] |" \
	" Your mission is to get all the ducks and exit the map.\n");

	// 4. Init MLX
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_key, &vars);
	mlx_hook(vars.win, DestroyNotify, KeyPressMask, &close_window, &vars);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_loop(vars.mlx);
	ft_free_tab(vars.map.grid);
	ft_free_tabs(2, vars.map.map_path, vars.mlx);
}
