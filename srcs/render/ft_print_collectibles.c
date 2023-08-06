/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_collectibles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:10:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 09:10:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_collectibles(t_vars *vars, t_pos pos, int total_coll, int coll)
{
	char	*string;
	char	*coll_str;
	char	*total_coll_str;
	char	*temp_string;

	total_coll_str = ft_itoa(total_coll);
	coll_str = ft_itoa(coll);
	string = ft_strjoin("Collectibles: ", total_coll_str);
	free(total_coll_str);
	total_coll_str = NULL;
	temp_string = ft_strjoin(string, " / ");
	free(string);
	string = temp_string;
	temp_string = ft_strjoin(string, coll_str);
	free(string);
	string = temp_string;
	mlx_string_put(vars->mlx, vars->win, pos.x, pos.y, BLACK_PIXEL, string);
	ft_free_tabs(2, coll_str, string);
}
