/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:49:00 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 14:10:23 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*get_fract(char *fract)
{
	if (!ft_strcmp("mandelbrot", fract) || !ft_strcmp("mdlb", fract))
		return ((void*)draw_mandel);
	else if (!ft_strcmp("julia", fract) || !ft_strcmp("jia", fract))
		return ((void*)draw_julia);
	else if (!ft_strcmp("burningship", fract) || !ft_strcmp("bship", fract))
		return ((void*)draw_julia);
	else
		return (NULL);
}

void		get_frac_ocl(char *fract, t_mlx *set)
{
	if (!ft_strcmp("mandelbrot", fract) || !ft_strcmp("mdlb", fract))
	{
		set->id = set->id = 1;
		set->frac = ft_strdup("mandelbrot.cl");
	}
	if (!ft_strcmp("julia", fract) || !ft_strcmp("jia", fract))
	{
		set->id = set->id = 2;
		set->frac = ft_strdup("julia.cl");
	}
	if (!ft_strcmp("burningship", fract) || !ft_strcmp("bship", fract))
	{
		set->id = set->id = 3;
		set->frac = ft_strdup("burningship.cl");
	}
}
