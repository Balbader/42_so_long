/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:55:08 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 16:55:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define TILE_SIZE 64

// ERROR CODES
# define MLX_ERROR		1
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

// KEYCODES FOR LINUX
# ifdef __linux__
#  define ESCAPE 65307
#  define W 119
#  define S 115
#  define A 97
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
# endif

// MLX_COLORS
# define RED_PIXEL 0XFF0000
# define GREEN_PIXEL 0XFF00
# define WHITE_PIXEL 0XFFFFFF
# define BLACK_PIXEL 0X000000

// PRINTF_COLORS
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0;37m"

// MAP TILE CODES
# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_START 'P'
# define MID_WALL 'M'

#endif // !DEFINE_H
