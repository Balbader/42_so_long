/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:15:39 by baalbade          #+#    #+#             */
/*   Updated: 2023/07/04 17:15:41 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct s_content
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_content;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	char		**map;
	t_content	content;
	t_img		img;
	t_pos		pos;
	int			count;
}				t_data;

// map_checker.c
int				ft_check_column(char *map_line, char wall, t_data *data);
int				ft_check_wall(char *map_line, char wall);
int				ft_check_map_viability(char *map_line, t_content *content);
int				ft_check_format(char **map);
void			ft_check_content(t_data *data);

// map.c
char			*ft_get_map_line(int fd);
char			**ft_parse_map(int fd, t_data *data);
char			**ft_run_map(char **av, t_data *data);
void			*ft_free_map(t_data *data);

// render.c
int				ft_render(t_data *data);
void			ft_render_background(t_data *data);
void			ft_render_other(t_data *data);
void			ft_render_main(t_data *data);
void			ft_print_img(t_data *data, void *img, int x, int y);

// render_mouv.c
void			ft_render_top(t_data *data);
void			ft_render_right(t_data *data);
void			ft_render_left(t_data *data);
void			ft_render_down(t_data *data);

// set.c
void			ft_set_content(t_content *content);
void			ft_set_image(t_data *data);

// texture.c
int				ft_check_collectible(t_data *data);
int				ft_end_game(t_data *data);
int				ft_key_press(int keysym, t_data *data);

//main.c
int				main(int argc, char **argv);

// ft_printf
int				ft_printf(const char *str, ...);
void			ft_print_nb(int nb, int *tot_len);
void			ft_print_hexa(unsigned int nb, char c, int *tot_len);
void			ft_print_unsigned(unsigned int u, int *tot_len);
void			ft_print_ptr(size_t ptr, int *tot_len);
void			ft_print_char(char c, int *tot_len);
void			ft_print_str(char *str, int *tot_len);

// gnl
char			*ft_stradd(char *str, char buff);
int				ft_get_next_line(int fd, char **str);

// utils.c
int				ft_is_duplicate(char *str);
void			*ft_print_error(char *str);
long long int	ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_strchr(char *str, char *cmp);
int				ft_isdigit(int c);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_itoa(int n);
char			**ft_split(char *str, char sep);
char			*ft_strdup(char *str);
char			*ft_strncpy(char *str, int nb);
char			*ft_strjoin(char *s1, char *s2);

#endif
