/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracolors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:51:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/17 22:56:24 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_colors(t_mlx *set, t_frac mand)
{
	if (mand.i == MAX_ITER)
		mlx_pixel_put(set->mlx, set->win, mand.x, mand.y, 0);
	else
		mlx_pixel_put(set->mlx, set->win, mand.x, mand.y,
				0x0000 + mand.i * 255 / MAX_ITER);
}
