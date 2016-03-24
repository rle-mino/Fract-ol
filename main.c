/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:06:54 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/23 01:56:22 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_mlx	*set;

	(void)ac;
	(void)av;
	if (!(set = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		frac_err(MALLOR);
	set->mlx = mlx_init();
	set->win = mlx_new_window(set->mlx, 1000, 1000, "Fract'ol");
	mandel(set);
}
