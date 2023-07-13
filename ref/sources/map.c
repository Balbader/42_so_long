#include "gui.h"

t_type	map2typ(char c)
{
	if (c == '0')
		return (background);
	else if (c == '1')
		return (wall);
	else if (c == 'C')
		return (collectible);
	else if (c == 'E')
		return (map_exit);
	else if (c == 'P')
		return (player);
	return (garbage);
}

char	*full_line(char *s, char c)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(s) - 1)
		if (s[i] != c)
			break ;
	if (s[i] != c && i != (int)ft_strlen(s) - 1)
		return (&s[i]);
	else
		return (NULL);
}

char	**parse_map(t_gui *gui, char *map_lines, int path_fd, int sz)
{
	char	*tmp;
	char	*buf;
	char	**res;

	buf = get_next_line(path_fd);
	if (buf)
	{
		tmp = ft_strjoin(map_lines, buf);
		free(map_lines);
		if ((sz != -42 && (sz != (int)ft_strlen(buf) - 1
					|| (buf[0] != '1' || buf[sz - 1] != '1')))
			|| (sz == -42 && full_line(buf, '1')))
			err(map_shape_error);
		sz = ft_strlen(buf) - 1;
		free(buf);
		gui->map_h++;
		return (parse_map(gui, tmp, path_fd, sz));
	}
	else if (!map_lines[0] || (full_line(&map_lines[((sz + 1)
						* (gui->map_h - 1)) + 1], '1') && !err(nb_error)))
		err(map_shape_error);
	gui->map_w = sz;
	res = ft_split(map_lines, '\n');
	free(map_lines);
	return (res);
}

int	new_map(t_gui *gui, char *map_path)
{
	int		path_fd;

	path_fd = open(map_path, O_RDONLY);
	if (path_fd == -1 || !ft_strnstr(map_path, ".ber\0", 50)
		|| ft_strnstr(map_path, ".ber\0", 50)[4])
	{
		if (path_fd != -1)
			close(path_fd);
		return (err(map_404_error));
	}
	gui->map_h = 0;
	gui->map = parse_map(gui, ft_strdup(""), path_fd, -42);
	close(path_fd);
	if (!gui->map || err(nb_error))
		return (1);
	if (count(gui->map, gui->map_h, gui->map_w, garbage))
		return (err(map_garbage_error));
	return (check_map(gui, 0));
}

void	destroy_map(char **map, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
}
