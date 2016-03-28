/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 14:42:46 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 16:39:24 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			adjust_burning_val(t_frac *burn)
{
	burn->c_r = burn->x / burn->zoom_x + burn->x1;
	burn->c_i = burn->y / burn->zoom_y + burn->y1;
	burn->z_r = 0;
	burn->z_i = 0;
	burn->i = 0;
}

void			draw_burning(t_mlx *set, t_frac burn)
{
	while (++burn.x < 1000)
	{
		burn.y = -1;
		while (++burn.y < 1000)
		{
			adjust_burning_val(&burn);
			while (((burn.z_r * burn.z_r) + (burn.z_i * burn.z_i)) < 4 &&
											burn.i < burn.iter)
			{
				burn.tmp = fabs(burn.z_r * burn.z_i);
				burn.z_r = (burn.z_r * burn.z_r) - (burn.z_i * burn.z_i)
															+ burn.c_r;
				burn.z_i = burn.tmp + burn.tmp + burn.c_i;
				burn.i += 1;
			}
			draw_colors(set, burn);
		}
	}
}
