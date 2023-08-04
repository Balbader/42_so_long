/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 08:43:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 08:43:50 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		index;

	index = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buffer[index])
			buffer[index++] = 0;
		return (0);
	}
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		line = strjoin(line, buffer);
		if (ft_manage_buffer(buffer))
			break ;
	}
	return (line);
}
