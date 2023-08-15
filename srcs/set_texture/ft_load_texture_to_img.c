/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture_to_img.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:25:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/05 08:25:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	ft_load_texture_to_img(t_vars *vars, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(vars->mlx, path, &img.width, \
	&img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
