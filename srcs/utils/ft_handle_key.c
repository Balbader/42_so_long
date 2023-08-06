#include "so_long.h"

int	ft_handle_key(int key, t_vars *vars)
{
	if (key == ESCAPE)
		close_window(vars);
	if (key == W || key == UP)
		vars->player.move.up = 1;
	if (key == S || key == DOWN)
		vars->player.move.down = 1;
	if (key == A || key == LEFT)
		vars->player.move.left = 1;
	if (key == D || key == RIGHT)
		vars->player.move.right = 1;
	return (EXIT_SUCCESS);
}
