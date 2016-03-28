/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 02:44:07 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 13:20:54 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		adjust_julia_val(t_frac *jia)
{
	jia->c_r = jia->tmp_z_r;
	jia->c_i = jia->tmp_z_i;
	jia->z_r = jia->x / jia->zoom_x + jia->x1;
	jia->z_i = jia->y / jia->zoom_y + jia->y1;
	jia->i = 0;
}

void		draw_julia(t_mlx *set, t_frac jia)
{
	while (++jia.x < 1000)
	{
		jia.y = -1;
		while (++jia.y < 1000)
		{
			adjust_julia_val(&jia);
			while (((jia.z_r * jia.z_r) + (jia.z_i * jia.z_i)) < 4 &&
					jia.i < jia.iter)
			{
				jia.tmp = jia.z_r;
				jia.z_r = (jia.z_r * jia.z_r) - (jia.z_i * jia.z_i) + jia.c_r;
				jia.z_i = 2 * jia.z_i * jia.tmp + jia.c_i;
				jia.i += 1;
			}
			draw_colors(set, jia);
		}
	}
}
