/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:35:29 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 17:35:31 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	swap;

	i = 0;
	size = ft_strlen(str) - 1;
	while (size > i)
	{
		swap = str[i];
		str[i] = str[size];
		str[size] = swap;
		size--;
		i++;
	}
	return (str);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i] = (n % 10) * sign + '0';
		i++;
		n = n / 10;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
