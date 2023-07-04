/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:09:27 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:09:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_run_map(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (ft_print_error("Error.\nNo '.ber' file detected.\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = ft_parse_map(fd, data);
		else
			return (ft_print_error("Error.\nFailure to open '.ber' file.\n"));
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			ft_free_map(data);
			return (ft_print_error(
					"Error\nNeed 1 Player/Exit and at least 1 Object\n"));
		}
	}
	return (data->map);
}
