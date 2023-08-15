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

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <X11/X.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int				main(int ac, char **av);

/* map check */
bool			fill(int y, int x, t_map *map);
void			ft_flood_fill(int y, int x, t_map *map);
void			ft_map_size(t_map *map);
bool			ft_check_path(t_map *map);
bool			ft_validate_content(t_map *map);
bool			ft_check_if_open(t_map *map);
bool			ft_check_format(t_map *map);
bool			ft_count_content(t_map *map, char c);
bool			ft_validate_map(t_vars *vars);

/* map_parsing */
void			ft_parse_map(const char *path_to_map, t_map *map);
char			*ft_read_map(int fd);

/* render */
int				ft_render(t_vars *vars);
unsigned int	ft_get_pixel(t_img *img, int x, int y);
void			ft_render_player(t_vars *vars);
void			ft_render_map(t_vars *vars);
void			ft_put_sprite_to_map(t_vars *vars, t_pos pos, char c);
void			ft_put_pixel(t_img *img, int x, int y, int color);
void			ft_copy_img(t_img img, t_pos pos, t_img *final_img);
void			ft_move_player(t_map *map, t_player *player, int x, int y);
void			ft_confirm_move(t_vars *vars);
bool			ft_is_obstacle(char grid_value);

/* set textures */
/* init textures */
void			ft_init_win(t_vars *vars);
void			ft_init_textures(t_vars *vars);
t_img			ft_load_texture_to_img(t_vars *vars, char *path);

/* init textures utils 1 */
void			ft_set_map_exit(t_vars *vars);
void			ft_set_floor(t_vars *vars);
void			ft_set_collectibles(t_vars *vars);
void			ft_set_wall(t_vars *vars);
void			ft_set_mid_wall(t_vars *vars);

/* init textures utils 2 */
void			ft_set_player(t_vars *vars);

/* utils */
int				ft_close_window(t_vars *vars);
int				ft_handle_key(int key, t_vars *vars);
char			**ft_duplicate_map(t_map *map);
void			ft_map_error(t_map *map);
t_pos			ft_find_pos(char **map, char stuff);
bool			ft_check_file_extension(const char *file_name);
bool			ft_check_main_args(int ac, char **av);

/* GNL */
char			*get_next_line(int fd);
char			*strjoin(char *line, char *buffer);
bool			ft_manage_buffer(char *buffer);

/* ft_printf */
int				ft_printf(const char *str, ...);
void			ft_print_nb(int nb, int *tot_len);
void			ft_print_hexa(unsigned int nb, char c, int *tot_len);
void			ft_print_unsigned(unsigned int u, int *tot_len);
void			ft_print_ptr(size_t ptr, int *tot_len);
void			ft_print_char(char c, int *tot_len);
void			ft_print_str(char *str, int *tot_len);

/* libft */
int				ft_strncmp( const char *s1, const char *s2, size_t n );
size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(const char *s, char c);
void			ft_free_tab(char **tab);
void			ft_free_tabs(unsigned int count, ...);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif // !SO_LONG_H
