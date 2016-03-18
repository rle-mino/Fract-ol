/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:50:40 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/18 22:04:41 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		restart_mandel(t_param *a)
{
	mlx_destroy_image(a->set->mlx, a->set->img);
	a->set->img = mlx_new_image(a->set->mlx, 1000, 1000);
	a->set->img_data = mlx_get_data_addr(a->set->img, &a->set->nbit,
			&a->set->line, &a->set->endian);
	draw_mandel(a->set, *(a->mand));
	mlx_put_image_to_window(a->set->mlx, a->set->win, a->set->img, 0, 0);
}

int			mouse_func_mand(int x, int y, void *param)
{
	t_param	*a;

	a = param;
	if (a->mand_zoom != 1)
	{
		a->set->z_r = ((double)(x - 500) / 500);
		a->set->z_i = ((double)(y - 500) / 500);
		restart_mandel(a);
	}
	return (0);
}

int			key_func_mand(int keycode, void *param)
{
	t_param	*a;

	a = param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 49)
		a->mand_zoom = a->mand_zoom == 1 ? 0 : 1;
	else
		fpf("keycode = %d\n", keycode);
	return (0);
}

int			zoom_func_mand(int button, int x, int y, void *param)
{
	t_param	*a;

	a = param;
	if (a->mand_zoom == 1)
	{
		if (button == 5)
		{
			a->set->mand_zoom_y += 0.2;
			a->set->mand_zoom_x += 0.2;
			a->set->mand_deca_x += ((double)(x - 500) / 500);
			a->set->mand_deca_y += ((double)(y - 500) / 500);
		}
		else if (button == 4)
		{
			a->set->mand_zoom_y -= 0.2;
			a->set->mand_zoom_x -= 0.2;
			a->set->mand_deca_x -= ((double)(x - 500) / 500);
			a->set->mand_deca_y -= ((double)(y - 500) / 500);
		}
		restart_mandel(a);
	}
	return (0);
}
