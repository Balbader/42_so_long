/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:14:31 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:14:33 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_wdcount(char *str, char chr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == chr)
			count++;
		i++;
	}
	return (count);
}

static int	ft_strnchr(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		y;
	int		cpt;
	char	**ret;

	i = 0;
	y = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_wdcount(str, sep) + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		cpt = ft_strnchr(&str[i], sep);
		ret[y] = ft_strncpy(&str[i], cpt);
		if (str[i + cpt] != '\0')
			i += (cpt + 1);
		else
			i += cpt;
		y++;
	}
	ret[y] = NULL;
	free(str);
	return (ret);
}
