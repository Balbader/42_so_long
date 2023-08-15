/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:16:28 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/06 17:16:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tabs(unsigned int count, ...)
{
	va_list	args;
	void	*tab;

	va_start(args, count);
	while (count)
	{
		tab = va_arg(args, void *);
		free(tab);
		count--;
	}
	va_end(args);
}
