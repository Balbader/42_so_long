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

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!str1 || !str2)
		return (NULL);
	newstr = malloc(sizeof(char) * ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!newstr)
		return (NULL);
	while (*str1)
		newstr[i++] = *str1++;
	while (*str2)
		newstr[i++] = *str2++;
	newstr[i] = '\0';
	return (newstr);
}
