/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:49:00 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 16:45:36 by rle-mino         ###   ########.fr       */
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
		return ((void*)draw_burning);
	else if (!ft_strcmp("celtic", fract) || !ft_strcmp("cel", fract))
		return ((void*)draw_celtic);
	else if (!ft_strcmp("druid", fract) || !ft_strcmp("drd", fract))
		return ((void*)draw_druid);
	else
		return (NULL);
}

void		get_frac_ocl(char *fract, t_mlx *set)
{
	if (!ft_strcmp("mandelbrot", fract) || !ft_strcmp("mdlb", fract))
	{
		set->id = 1;
		set->frac = ft_strdup("mandelbrot.cl");
	}
	if (!ft_strcmp("julia", fract) || !ft_strcmp("jia", fract))
	{
		set->id = 2;
		set->frac = ft_strdup("julia.cl");
	}
	if (!ft_strcmp("burningship", fract) || !ft_strcmp("bship", fract))
	{
		set->id = 3;
		set->frac = ft_strdup("burningship.cl");
	}
	if (!ft_strcmp("celtic", fract) || !ft_strcmp("cel", fract))
	{
		set->id = 4;
		set->frac = ft_strdup("celtic.cl");
	}
	if (!ft_strcmp("druid", fract) || !ft_strcmp("drd", fract))
	{
		set->id = 4;
		set->frac = ft_strdup("druid.cl");
	}
}
