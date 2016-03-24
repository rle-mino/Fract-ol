/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:39:00 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/22 00:03:20 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mandel(t_frac *mand)
{
	mand->x1 = -2.1;
	mand->x2 = 0.6;
	mand->y1 = -1.2;
	mand->y2 = 1.2;
	mand->zoom_x = 1000 / (mand->x2 - mand->x1);
	mand->zoom_y = 1000 / (mand->y2 - mand->y1);
	mand->x = -1;
	mand->iter = 50;
}

void		adjust_mand_val(t_frac *mand)
{
	mand->c_r = mand->x / mand->zoom_x + mand->x1;
	mand->c_i = mand->y / mand->zoom_y + mand->y1;
	mand->z_r = mand->tmp_z_r;
	mand->z_i = mand->tmp_z_i;
	mand->i = 0;
}

void		draw_mandel(t_mlx *set, t_frac mand)
{
	while (++mand.x < 1000)
	{
		mand.y = -1;
		while (++mand.y < 1000)
		{
			adjust_mand_val(&mand);
			while (((mand.z_r * mand.z_r) + (mand.z_i * mand.z_i)) < 4 &&
											mand.i < mand.iter)
			{
				mand.tmp = mand.z_r;
				mand.z_r = (mand.z_r * mand.z_r) - (mand.z_i * mand.z_i)
															+ mand.c_r;
				mand.z_i = (2 * mand.z_i * mand.tmp) + mand.c_i;
				mand.i += 1;
			}
			draw_colors(set, mand);
		}
	}
}
