/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:33:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/13 11:33:45 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Uses GNL to open and read map.ber */

char	*ft_get_map_line(int fd)
{
	char	*line;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line = ft_strdup("");
	buff = ft_strdup("");
	char_count = ft_get_next_line(fd, &line);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line);
			free(tmp_buff);
			free(line);
			line = ft_strdup("");
			char_count = ft_get_next_line(fd, &line);
			tmp_buff = buff;
		}
		return (buff);
	}
	ft_print_error("Error.\n'.ber' not readable.\n");
	return (NULL);
}
