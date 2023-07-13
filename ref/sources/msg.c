/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emis <emis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:14:57 by emis              #+#    #+#             */
/*   Updated: 2023/01/19 12:29:37 by emis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

// ascii flower found on http://loveascii.com/flowers3.html
static void	msg_win_death(t_evt event)
{
	if (event == died_event)
	{
		ft_printf("\n%sYou were eaten by a %sslime%s!\n", FCOL, PUDD, NC);
		ft_printf("\n%s%sGAME OVER!%s%s\n\n", REDD, LINE, LINE, NC);
		return ;
	}
	ft_printf("%s\n", CLRL);
	ft_printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", PURP,
		"                             U    U    U    U\n",
		"                            U U  U U  U U U U\n",
		"                             U  U   U    U U\n",
		"                              U           U\n",
		"                               U*      *U\n",
		"                                  U()U\n", GREN,
		"                                 //\n",
		"                               //\n",
		"                    ()       //\n", "                   (())    //\n",
		"                   (())  // !()\n",
		"                   (())!//!(())\n",
		"                    ()!/  !()))\n", "                   //   !()))\n",
		"                 //  !(()))\n", "               ///!(())\n",
		"              /!(()\n", "            //\n", "           //\n",
		"          //\n", "         //\n", "         //\n", "        //\n",
		"       //\n\n");
	ft_printf("%s%sSUCCESS :)%s%s\n\n", PURP, LINE, LINE, NC);
}

int	msg_event(t_gui *gui, t_evt event)
{
	static int	win_death;

	if (event == start_event)
		ft_printf("%s%sGAME START%s%s\n\n", PUDD, LINE, LINE, NC);
	else if (event == collected_event)
	{
		if (gui->to_collect)
			ft_printf("%s%sPicked up a %sflower%s! %d left.", REST,
				FCOL, PURP, NC, gui->to_collect);
		else
			ft_printf("%s%sDone! You can now pay your %srespects%s.", REST,
				FCOL, PURP, NC);
	}
	else if ((event == win_event || event == died_event) && ++win_death)
	{
		msg_win_death(event);
		gui->mlx->end_loop = 1;
	}
	else if (event == exit_event)
		ft_printf("\n\n%s%sINTERRUPT!%s%s\n\n", REDD, LINE, LINE, NC);
	else if (event == enemy_slain_event)
		ft_printf("%s%sYou killed a %sslime%s!", REST, BCOL, PUDD, NC);
	else if (event == boss_slain_event)
		ft_printf("%s%sYou killed a %sboss%s!", REST, BCOL, REDD, NC);
	return (win_death);
}

int	msg_move(t_gui *gui, int final)
{
	static int	moves;
	char		*tmp;
	char		*tmpnb;

	if (!BONUS && final == -2)
		ft_printf("Number of moves: %s%3d", SAVE, moves);
	else if (!BONUS && !final)
		ft_printf("%s%3d", REST, ++moves);
	else if (BONUS && (final <= -1 || (!final && ++moves)))
	{
		if (final == -2)
			ft_printf("%s", SAVE);
		tmpnb = ft_itoa(moves);
		tmp = ft_strjoin("Number of moves: ", tmpnb);
		free(tmpnb);
		top_line_redraw(gui);
		mlx_string_put(gui->mlx, gui->mlx->win_list, (gui->map_w * 16) - 56,
			22, 0x99FFFF, tmp);
		free(tmp);
	}
	else if (final == 1)
		ft_printf("Total number of moves: %3d\n", ++moves);
	return (1);
}

static char	*map_err(t_err error)
{
	char	*msg;

	if (error == map_404_error)
		msg = "Map not found or does not have .ber extension.\n";
	else if (error == map_shape_error)
		msg = "Map not rectangular or not surrounded by walls.\n";
	else if (error == map_garbage_error)
		msg = "Map contains invalid character. (valid ones are 0,1,C,E,P)\n";
	else if (error == map_invalid_error)
		msg = "Map has a wrong number of start/exit/collectible(s).\n";
	else if (error == map_no_win_error)
		msg = "Map has no way to be completed.\n";
	else
		msg = "No one sees me\n";
	return (msg);
}

int	err(t_err error)
{
	static int	errnb;
	char		*msg;

	if (error == nb_error)
		return (errnb);
	else if (error == argument_error)
		msg = "Missing or excess argument(s).\nUsage: ./so_long <map>.ber\n";
	else if (error == malloc_error)
		msg = "Memory allocation failed.\n";
	else if (error == mlx_error)
		msg = "Minilibx failure.\n";
	else if (error == map_404_error || error == map_shape_error
		|| error == map_invalid_error || error == map_no_win_error
		|| error == map_garbage_error)
		msg = map_err(error);
	else if (error == img_404_error)
		msg = "Image could not be loaded.\n";
	else if (error == element_error)
		msg = "Element could not be created.\n";
	else
		msg = "Process terminated and allocated memory freed.\n";
	if (errnb == 0)
		write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	return (++errnb);
}
