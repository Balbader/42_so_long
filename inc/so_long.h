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
# include <stddef.h>
# include <X11/X.h>


/* ft_flood_fill */
bool	fill(int y, int x, t_map *map);
void	ft_flood_fillflood(int y, int x, t_map *map);

/* map validation */
bool	ft_check_path(t_map *map);
void	ft_parse_map(const char *path_to_map, t_map *map);
char	*ft_read_map(int fd);

/* set textures */
/* init textures */
void	ft_init_textures(t_vars *vars);
t_img	ft_load_texture_to_img(t_vars *vars, char *path);

/* init textures utils 1 */
void	ft_set_map_exit(t_vars *vars);
void	ft_set_empty_space(t_vars *vars);
void	ft_set_collectibles(t_vars *vars);
void	ft_set_wall(t_vars *vars);

/* init textures utils 2 */
void	ft_set_pc_up(t_vars *vars);
void	ft_set_pc_down(t_vars *vars);
void	ft_set_pc_left(t_vars *vars);
void	ft_set_pc_right(t_vars *vars);
void	ft_set_player(t_vars *vars);

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

/* libft */
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
void	ft_free_tab(char **tab);


#endif // !SO_LONG_H
