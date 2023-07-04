/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:07:36 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:07:38 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_print_error("Error.\nTotal aguments count incorrect.\n");
		return (0);
	}
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		ft_set_content(&(data.content));
		data.map = ft_run_map(av, &data);
		if (data.map != NULL)
		{
			ft_set_image(&data);
			ft_render_main(&data);
		}
		else
			ft_end_game(&data);
	}
	return (1);
}
