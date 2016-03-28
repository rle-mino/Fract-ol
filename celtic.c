/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:54:24 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 16:37:32 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		adjust_cel_val(t_frac *cel)
{
	cel->c_r = cel->x / cel->zoom_x + cel->x1;
	cel->c_i = cel->y / cel->zoom_y + cel->y1;
	cel->z_r = cel->tmp_z_r;
	cel->z_i = cel->tmp_z_i;
	cel->i = 0;
}

void		draw_celtic(t_mlx *set, t_frac cel)
{
	while (++cel.x < 1000)
	{
		cel.y = -1;
		while (++cel.y < 1000)
		{
			adjust_cel_val(&cel);
			while (((cel.z_r * cel.z_r) + (cel.z_i * cel.z_i)) < 4 &&
					cel.i < cel.iter)
			{
				cel.tmp = cel.z_r * cel.z_i;
				cel.z_r = fabs((cel.z_r * cel.z_r) - (cel.z_i * cel.z_i))
															+ cel.c_r;
				cel.z_i = cel.tmp + cel.tmp + cel.c_i;
				cel.i += 1;
			}
			draw_colors(set, cel);
		}
	}
}
