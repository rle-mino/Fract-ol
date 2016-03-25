/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracolors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:51:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/24 23:23:45 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_colors(t_mlx *set, t_frac mand)
{
	int		i;

	i = mand.x * set->deca_nbit + (mand.y * set->line);
	if (mand.i == mand.iter)
	{
		set->img_data[i] = 0;
		set->img_data[i + 1] = 0;
		set->img_data[i + 2] = 0;
	}
	else
	{
		set->img_data[i] = 0;
		set->img_data[i + 1] = 0;
		set->img_data[i + 2] = mand.i * 255 / mand.iter;
	}
}
