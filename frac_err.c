/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:18:31 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 16:35:01 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		frac_err(int flag)
{
	if (flag == MALLOR)
	{
		ft_putendl_fd("Malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	if (flag == USAGE)
	{
		ft_putendl_fd("Usage : ./fractol [fractal] (optional)[-gpu]", 2);
		ft_putendl_fd("Available fractals :\t" \
				"mandelbrot\t(mdlb)\n" \
				"\t\t\tjulia\t\t(jia)\n" \
				"\t\t\tburningship\t(bship)\n" \
				"\t\t\tceltic\t\t(cel)\n" \
				"\t\t\tdruid\t\t(drd)", 2);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
