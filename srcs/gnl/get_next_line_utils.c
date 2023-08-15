/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 08:43:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 08:43:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*strjoin(char *line, char *buffer)
{
	char	*new_line;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (buffer[0] == 0)
		return (0);
	new_line = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!new_line)
		return (0);
	while (line && line[index1])
	{
		new_line[index1] = line[index1];
		index1++;
	}
	free (line);
	while (buffer && buffer[index2] && buffer[index2] != '\n')
		new_line[index1++] = buffer[index2++];
	if (buffer[index2] == '\n')
		new_line[index1++] = '\n';
	new_line[index1] = '\0';
	return (new_line);
}

bool	ft_manage_buffer(char *buffer)
{
	size_t	index1;
	size_t	index2;
	bool	found_nl;

	index1 = 0;
	index2 = 0;
	found_nl = false;
	while (buffer[index1])
	{
		if (buffer[index1] == '\n')
		{
			found_nl = true;
			index1++;
			break ;
		}
		index1++;
	}
	while (buffer[index1])
		buffer[index2++] = buffer[index1++];
	while (index2 < index1)
		buffer[index2++] = '\0';
	return (found_nl);
}
