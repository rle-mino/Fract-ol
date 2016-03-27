/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:57:20 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/27 19:35:17 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		restart_fract(t_param *a)
{
	mlx_destroy_image(a->set->mlx, a->set->img);
	a->set->img = mlx_new_image(a->set->mlx, 1000, 1000);
	a->set->img_data = mlx_get_data_addr(a->set->img, &a->set->nbit,
			&a->set->line, &a->set->endian);
	if (a->set->gpu == 1)
		draw_fract_opencl(a->set, *(a->mand));
	else
		a->set->draw_fract(a->set, *(a->mand));
	mlx_put_image_to_window(a->set->mlx, a->set->win, a->set->img, 0, 0);
}

int			mouse_func_fract(int x, int y, void *param)
{
	t_param	*a;

	a = param;
	if (a->mand_zoom != 1)
	{
		a->mand->tmp_z_r = ((double)(x - 500) / 500);
		a->mand->tmp_z_i = ((double)(y - 500) / 500);
		restart_fract(a);
	}
	return (0);
}

void		move_fract(int keycode, t_frac *mand)
{
	if (keycode == 126)
		mand->y1 -= 0.01;
	if (keycode == 125)
		mand->y1 += 0.01;
	if (keycode == 123)
		mand->x1 -= 0.01;
	if (keycode == 124)
		mand->x1 += 0.01;
}

int			key_func_fract(int keycode, void *param)
{
	t_param	*a;

	a = param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 49)
		a->mand_zoom = a->mand_zoom == 1 ? 0 : 1;
	else if (keycode == 69 || keycode == 78 ||
			(keycode >= 123 && keycode <= 126))
	{
		if (keycode == 69)
			a->mand->iter += 5;
		else if (keycode == 78 && (a->mand->iter - 5) > 0)
			a->mand->iter -= 5;
		else if (keycode >= 123 && keycode <= 126)
			move_fract(keycode, a->mand);
		restart_fract(a);
	}
	return (0);
}

int			zoom_func_fract(int button, int x, int y, void *param)
{
	t_param	*a;

	a = param;
	if (a->mand_zoom == 1)
	{
		if (button == 5)
			zoom_plus_fract(a, x, y);
		else if (button == 4)
			zoom_min_fract(a, x, y);
		restart_fract(a);
	}
	return (0);
}
