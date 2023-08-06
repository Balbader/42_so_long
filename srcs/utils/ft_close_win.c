#include "so_long.h"

int	ft_close_window(t_vars *vars)
{
	ft_printf("[ " RED "XX" RESET " ] |" \
		" You exited the game before finishing :(\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
