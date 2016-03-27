/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracolors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:51:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/27 15:52:54 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_colors(t_mlx *set, t_frac frac)
{
	int		i;

	i = frac.x * set->deca_nbit + (frac.y * set->line);
	if (frac.i == frac.iter)
	{
		set->img_data[i] = 0;
		set->img_data[i + 1] = 0;
		set->img_data[i + 2] = 0;
	}
	else
	{
		set->img_data[i] = 0;
		set->img_data[i + 1] = 0;
		set->img_data[i + 2] = frac.i * 255 / frac.iter;
	}
}
