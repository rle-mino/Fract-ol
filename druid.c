/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   druid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:45:59 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 22:03:16 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		adjust_druid_val(t_frac *duid)
{
	duid->c_r = duid->x / duid->zoom_x + duid->x1;
	duid->c_i = duid->y / duid->zoom_y + duid->y1;
	duid->z_r = duid->tmp_z_r;
	duid->z_i = duid->tmp_z_i;
	duid->i = 0;
}

void		draw_druid(t_mlx *set, t_frac duid)
{
	while (++duid.x < 1000)
	{
		duid.y = -1;
		while (++duid.y < 1000)
		{
			adjust_druid_val(&duid);
			while (((duid.z_r * duid.z_r) + (duid.z_i * duid.z_i)) < 4 &&
					duid.i < duid.iter)
			{
				duid.tmp = duid.z_r * duid.z_i;
				if (duid.i % 2)
					duid.z_r = fabs((duid.z_r * duid.z_r) -
							(duid.z_i * duid.z_i)) + duid.c_r;
				else
					duid.z_r = (duid.z_r * duid.z_r) -
										(duid.z_i * duid.z_i) + duid.c_r;
				duid.z_i = duid.tmp + duid.tmp + duid.c_i;
				duid.i += 1;
			}
			draw_colors(set, duid);
		}
	}
}
