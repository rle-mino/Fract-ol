/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:39:11 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/18 00:07:47 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandel(t_mlx *set)
{
	t_frac	mand;
	t_param	*param;

	init_mandel(&mand);
	if (!(param = (t_param *)ft_memalloc(sizeof(t_param))))
		frac_err(MALLOR);
	param->set = set;
	param->mand = &mand;
	draw_mandel(set, mand);
	mlx_hook(set->win, 2, 0, key_func, 0);
	mlx_hook(set->win, 6, 0, mouse_func, param);
	mlx_loop(set->mlx);
}
