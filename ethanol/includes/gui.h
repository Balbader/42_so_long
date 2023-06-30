/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:00:17 by emis              #+#    #+#             */
/*   Updated: 2023/01/19 13:24:11 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

/* INCLUDES */

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>

# define DEFAULT_SIZE_X 1000
# define DEFAULT_SIZE_Y 750
# define TITLE "Dungeon-Dwelling Deadling"

/* BONUS */

# ifndef BONUS
#  define BONUS 0
# endif

/* TERMINAL AESTHETIC */

# define CLR "\033[2J"
# define CLRL "\033[2K"
# define FCOL "\033[5C"
# define BCOL "\033[42C"
# define SAVE "\033[s"
# define REST "\033[u"
# define PURP "\033[1;38;5;135m"
# define PUDD "\033[1;38;5;10m"
# define REDD "\033[1;38;5;9m"
# define GREN "\033[1;38;5;22m"
# define NC "\033[0m"
# define LINE ".:*~*:._.:*~*:._.:*~*:._.:*~*:."

/* IMG PATHS */

# define PATH_TEXTURES "./textures/"

/* KEYBINDS */

# ifndef KEYS_WASD
#  define KEYS_WASD 1
# endif

# if KEYS_WASD

typedef enum e_keybinds
{
	up = XK_w,
	down = XK_s,
	left = XK_a,
	right = XK_d,
	attack = XK_space
}	t_kbind;
# elif KEYS_ZQSD

typedef enum e_keybinds
{
	up = XK_z,
	down = XK_s,
	left = XK_q,
	right = XK_d,
	attack = XK_space
}	t_kbind;
# else

typedef enum e_keybinds
{
	up = XK_Up,
	down = XK_Down,
	left = XK_Left,
	right = XK_Right,
	attack = XK_space
}	t_kbind;
# endif

/* ERRORS */

typedef enum e_error
{
	nb_error,
	argument_error,
	malloc_error,
	mlx_error,
	map_404_error,
	map_shape_error,
	map_garbage_error,
	map_invalid_error,
	map_no_win_error,
	img_404_error,
	element_error
}	t_err;

/* EVENTS */

typedef enum e_event
{
	start_event,
	exit_event,
	died_event,
	collected_event,
	enemy_slain_event,
	boss_slain_event,
	win_event
}	t_evt;

/* TYPES */

typedef enum e_elmt_type
{
	background,
	wall,
	collectible,
	map_exit,
	player,
	enemy,
	garbage
}	t_type;

/* ELEMENTS */

typedef struct s_elmt_list
{
	t_type				type;
	int					x;
	int					y;
	int					img;
	int					img_list_size;
	t_img				**img_list;
	struct s_elmt_list	*next;
}	t_els;

/* GUI */

typedef struct s_gui
{
	t_xvar	*mlx;
	int		map_w;
	int		map_h;
	char	**map;
	t_els	**el;
	t_els	*player;
	int		to_update;
	int		to_collect;
}	t_gui;

/* MSG */

int		msg_event(t_gui *gui, t_evt event);
int		msg_move(t_gui *gui, int final);
int		err(enum e_error error);

/* ELEMENT */

t_els	*new_els(t_gui *gui, t_type type, int x, int y);
int		add_els(t_els **els, t_els *to_add);
int		el_init(t_gui *gui);
int		count(char	**map, int h, int w, t_type type);

/* IMG */

t_img	**img_list_from_type(t_gui *gui, t_type type, int size);
int		img_list_size_from_type(t_type type);

/* CHK */

int		printmap(char **map_copy);
int		check_map(t_gui *gui, int status);
int		check_move(t_kbind key, t_gui *gui);

/* MAP */

t_type	map2typ(char c);
char	*full_line(char *s, char c);
int		new_map(t_gui *gui, char *map_path);
void	destroy_map(char **map, int height);

/* KEY */

void	player_animate(int keycode, t_gui *gui);
int		key_press(int keycode, t_gui *gui);
int		key_rel(int keycode, t_gui *gui);

/* GUI */

t_gui	*new_gui(char *map_path);
int		gui_refresh(t_gui *gui);
int		gui_kill(t_gui *gui);

/* DRW */

void	top_line_redraw(t_gui *gui);
int		background_redraw(t_gui *gui);
void	tile_redraw(t_gui *gui, int x, int y);
void	point_draw(t_gui *gui, int x, int y, int size);
void	enemies_redraw(t_gui *gui);

/* ANM BONUS */

int		enemies_time_crush(t_gui *gui);
int		slash(t_gui *gui);

/* ENM BONUS */

double	distance(t_gui *gui, int x, int y);
t_els	*enemy_at(t_gui *gui, int x, int y, int a);
int		necromancy(t_gui *gui);
int		enemies(t_gui *gui);

#endif