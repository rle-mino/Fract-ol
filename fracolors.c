/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracolors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:51:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/19 19:38:04 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_colors(t_mlx *set, t_frac mand)
{
	if (mand.i == mand.iter)
	{
		set->img_data[mand.x * set->deca_nbit + (mand.y * set->line)] = 0;
		set->img_data[mand.x * set->deca_nbit + (mand.y * set->line) + 1] = 0;
		set->img_data[mand.x * set->deca_nbit + (mand.y * set->line) + 2] = 0;
	}
	else
	{
		set->img_data[mand.x * set->deca_nbit + (mand.y * set->line)] = 0;
		set->img_data[mand.x * set->deca_nbit + (mand.y * set->line) + 1] = 0;
		set->img_data[mand.x * set->deca_nbit + (mand.y * set->line) + 2] =
													mand.i * 255 / mand.iter;
	}
}
