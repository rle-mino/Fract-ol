/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:49:00 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 02:56:26 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*get_fract(char *fract)
{
	if (!ft_strcmp("mandelbrot", fract) || !ft_strcmp("mdlb", fract))
		return ((void*)draw_mandel);
	else if (!ft_strcmp("julia", fract) || !ft_strcmp("jia", fract))
		return ((void*)draw_julia);
	else
		return (NULL);
}

char		*get_frac_ocl(char *fract)
{
	if (!ft_strcmp("mandelbrot", fract) || !ft_strcmp("mdlb", fract))
		return (ft_strdup("mandelbrot.cl"));
	return (NULL);
}
