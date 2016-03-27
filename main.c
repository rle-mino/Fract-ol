/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:06:54 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/27 19:35:28 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_mlx	*set;

	if (ac < 2 || ac > 3)
		frac_err(USAGE);
	if (!(set = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		frac_err(MALLOR);
	set->gpu = 0;
	set->mlx = mlx_init();
	set->win = mlx_new_window(set->mlx, 1000, 1000, "Fract'ol");
	if (ac == 3 && !ft_strcmp("-gpu", av[2]))
		set->gpu = 1;
	else if (ac == 3)
		frac_err(USAGE);
	if (!(set->draw_fract = get_fract(av[1])))
		frac_err(USAGE);
	set->frac = get_frac_ocl(av[1]);
	fractal(set);
}
