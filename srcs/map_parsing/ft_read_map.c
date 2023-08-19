/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:38:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/04 11:38:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_map(int fd)
{
	char	*line;
	char	*text;
	char	*temp;

	text = ft_strdup("");
	if (!text)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(text, line);
		ft_free_tabs(2, text, line);
		text = temp;
		line = get_next_line(fd);
	}
	return (text);
}
