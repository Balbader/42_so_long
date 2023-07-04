/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:09:09 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:09:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = ft_get_next_line(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = ft_get_next_line(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	ft_print_error("Error.\n'.ber' not readable.\n");
	return (NULL);
}
