/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:39:00 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/18 22:04:28 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mandel(t_frac *mand, t_mlx *set)
{
	mand->x1 = -2.1 + set->mand_deca_x;
	mand->x2 = 0.6 + set->mand_deca_x;
	mand->y1 = -1.2 + set->mand_deca_y;
	mand->y2 = 1.2 + set->mand_deca_y;
	mand->zoom_x = 1000 / (mand->x2 - (mand->x1 + set->mand_zoom_x));
	mand->zoom_y = 1000 / (mand->y2 - (mand->y1 + set->mand_zoom_y));
	mand->x = -1;
}

void		adjust_mand_val(t_frac *mand, t_mlx *set)
{
	mand->c_r = mand->x / mand->zoom_x + mand->x1;
	mand->c_i = mand->y / mand->zoom_y + mand->y1;
	mand->z_r = set->z_r;
	mand->z_i = set->z_i;
	mand->i = 0;
}

void		draw_mandel(t_mlx *set, t_frac mand)
{
	init_mandel(&mand, set);
	while (++mand.x < 1000)
	{
		mand.y = -1;
		while (++mand.y < 1000)
		{
			adjust_mand_val(&mand, set);
			while (((mand.z_r * mand.z_r) + (mand.z_i * mand.z_i)) < 4 &&
														mand.i < MAX_ITER)
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
