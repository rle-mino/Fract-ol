/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:20:44 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/27 19:29:14 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_plus_fract(t_param *a, int x, int y)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = a->mand->zoom_x;
	tmp_y = a->mand->zoom_y;
	a->mand->zoom_x *= 2;
	a->mand->zoom_y *= 2;
	a->mand->x1 += x / tmp_x - (x / a->mand->zoom_x);
	a->mand->y1 += y / tmp_y - (y / a->mand->zoom_y);
	a->mand->iter += 10;
}

void	zoom_min_fract(t_param *a, int x, int y)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = a->mand->zoom_x;
	tmp_y = a->mand->zoom_y;
	a->mand->zoom_x /= 2;
	a->mand->zoom_y /= 2;
	a->mand->x1 += x / tmp_x - (x / a->mand->zoom_x);
	a->mand->y1 += y / tmp_y - (y / a->mand->zoom_y);
	a->mand->iter -= 10;
}
