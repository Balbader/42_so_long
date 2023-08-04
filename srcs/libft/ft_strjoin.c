/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:35:39 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 17:35:41 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	tot_len;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		new_str = NULL;
	tot_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (tot_len + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}
