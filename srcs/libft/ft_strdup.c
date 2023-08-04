/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:35:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 17:35:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	str_len;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!dup)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
		dup[j++] = str[i++];
	dup[j] = '\0';
	return (dup);
}
