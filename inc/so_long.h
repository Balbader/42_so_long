/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:46:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 16:46:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "structures.h"
# include "define.h"

# include <stdlib.h>
# include <stdio.h>
#include <stddef.h>
# include <X11/X.h>

/* GNL */
char	*get_next_line(int fd);
char	*strjoin(char *line, char *buffer);
bool	ft_manage_buffer(char *buffer);

/* ft_printf */
int		ft_printf(const char *str, ...);
void	ft_print_nb(int nb, int *tot_len);
void	ft_print_hexa(unsigned int nb, char c, int *tot_len);
void	ft_print_unsigned(unsigned int u, int *tot_len);
void	ft_print_ptr(size_t ptr, int *tot_len);
void	ft_print_char(char c, int *tot_len);
void	ft_print_str(char *str, int *tot_len);

#endif // !SO_LONG_H
