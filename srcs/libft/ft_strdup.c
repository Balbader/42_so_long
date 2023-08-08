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

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	strsize;

	strsize = ft_strlen(s);
	d = (char *)malloc(strsize + 1);
	if (!d)
		return (0);
	ft_memcpy(d, s, strsize);
	d[strsize] = 0;
	return (d);
}
