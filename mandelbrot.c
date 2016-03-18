/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:39:11 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/18 21:05:40 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mand_set(t_mlx *set)
{
	set->z_r = 0;
	set->z_i = 0;
	set->mand_zoom_x = 0;
	set->mand_zoom_y = 0;
	set->mand_deca_x = 0;
	set->mand_deca_y = 0;
	set->img = mlx_new_image(set->mlx, 1000, 1000);
	set->img_data = mlx_get_data_addr(set->img, &set->nbit, &set->line,
															&set->endian);
}

void		mandel(t_mlx *set)
{
	t_frac	mand;
	t_param	*param;

	init_mandel(&mand, set);
	if (!(param = (t_param *)ft_memalloc(sizeof(t_param))))
		frac_err(MALLOR);
	param->set = set;
	param->mand_zoom = 0;
	param->mand = &mand;
	init_mand_set(set);
	draw_mandel(set, mand);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	mlx_hook(set->win, 2, 0, key_func_mand, param);
	mlx_hook(set->win, 4, 0, zoom_func_mand, param);
	mlx_hook(set->win, 6, 0, mouse_func_mand, param);
	mlx_loop(set->mlx);
}
