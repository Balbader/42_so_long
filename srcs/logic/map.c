/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:52:00 by baalbade          #+#    #+#             */
/*   Updated: 2023/06/28 13:52:06 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = ft_get_next_line(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = ft_get_next_line(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	ft_print_error("Error.\n'.ber' not readable.\n");
	return (NULL);
}

void	*ft_free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	**ft_parse_map(int fd, t_data *data)
{
	int		i;

	i = 1;
	data->map = ft_split(ft_get_map(fd), '\n');
	ft_check_content(data);
	if (!(ft_check_format(data->map)))
		return (ft_free_map(data));
	if (!(ft_check_line(data->map[0], data->content.wall)))
		return (ft_free_map(data));
	while (data->map[i] != NULL)
	{
		if (!(ft_check_col(data->map[i], data->content.wall, data)))
			return (ft_free_map(data));
		else if (!(ft_check_other(data->map[i], &(data->content))))
			return (ft_free_map(data));
		i++;
	}
	data->height = i;
	if (!(ft_check_line(data->map[i - 1], data->content.wall)))
		return (ft_free_map(data));
	return (data->map);
}

char	**ft_run_map(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (ft_print_error("Error.\nNo '.ber' file detected.\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = ft_parse_map(fd, data);
		else
			return (ft_print_error("Error.\nFailure to open '.ber' file.\n"));
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			ft_free_map(data);
			return (ft_print_error(
					"Error\nNeed 1 Player/Exit and at least 1 Object\n"));
		}
	}
	return (data->map);
}
