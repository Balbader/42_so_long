/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:59:52 by emis              #+#    #+#             */
/*   Updated: 2022/12/08 14:22:29 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstdelone(t_clist *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst -> cont);
		free(lst);
	}
}
