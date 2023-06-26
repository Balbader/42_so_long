/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:40:39 by baalbade          #+#    #+#             */
/*   Updated: 2023/04/30 19:40:43 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/includes/libft.h"
#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*block;
	void	*player;
	void	*collectible;

	char	**map;

	int		x;
	int		y;
	int		width;
	int		height;
	int		fd;
	int		player;
	int		column;
	int		exit;
	int		counter;
	int		collectibles;
}				t_data;

#endif
