/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 07:58:15 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/07 07:58:16 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* returns true if '.ber' file */
bool	ft_check_file_extension(const char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 5 || ft_strncmp(file_name + (len - 4), ".ber", 4) == 0)
		return (true);
	return (false);
}
