/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracolors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:51:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/18 16:38:14 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_colors(t_mlx *set, t_frac mand)
{
	if (mand.i == MAX_ITER)
	{
		set->img_data[mand.x * (set->nbit / 8) + (mand.y * set->line)] = 0;
		set->img_data[mand.x * (set->nbit / 8) + (mand.y * set->line) + 1] = 0;
		set->img_data[mand.x * (set->nbit / 8) + (mand.y * set->line) + 2] = 0;
	}
	else
	{
		set->img_data[mand.x * (set->nbit / 8) + (mand.y * set->line)] = 0;
		set->img_data[mand.x * (set->nbit / 8) + (mand.y * set->line) + 1] = 0;
		set->img_data[mand.x * (set->nbit / 8) + (mand.y * set->line) + 2] =
														mand.i * 255 / MAX_ITER;
	}
}
