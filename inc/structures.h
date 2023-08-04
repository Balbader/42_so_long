/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:55:21 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/03 16:55:22 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

/* Position Struct */
typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

/* struct to test map's validity */
typedef struct s_flood
{
	bool			exit_reached;
	unsigned int	collectibles_collected;
}				t_flood;

/* Image Struct */
typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_img;

/* Game Struct */
typedef struct s_map
{
	char			**grid;
	char			*map_path;
	size_t			height;
	size_t			width;
	unsigned int	wall_count;
	unsigned int	pc_count;
	unsigned int	collectible_count;
	unsigned int	empty_space_count;
	unsigned int	map_exit_count;
	unsigned int	map_start_count;
	t_img			wall;
	t_img			empty_space;
	t_img			map_exit;
	t_img			map_start;
	t_img			pc_up;
	t_img			pc_down;
	t_img			pc_left;
	t_img			pc_right;
	t_img			collectible;
	t_flood			flood;
}				t_map;

/* Move Struct */
typedef struct s_move
{
	int			up;		
	int			down;
	int			left;
	int			right;
}				t_move;

/* Player Struct */
typedef struct s_player
{
	t_img			img;
	t_pos			pos;
	t_move			move;
	unsigned int	collectible_count;
	unsigned int	move_count;
}				t_player;

/* MLX Variables Struct */
typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	win_height;
	unsigned int	win_width;
	t_map			map;
	t_player		player;
	t_img			final_image;
}					t_vars;

#endif // !STRUCTURES_H
