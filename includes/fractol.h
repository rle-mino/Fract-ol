/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/18 00:06:07 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

# define MAX_ITER 75

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_frac
{
	double		x1;
	double		y1;
	int			x;
	int			y;
	double		x2;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			i;
	double		tmp;
	double		zoom_y;
	double		zoom_x;
}				t_frac;

typedef struct	s_param
{
	t_frac		*mand;
	t_mlx		*set;
}				t_param;

enum
{
	ERRNO,
	MALLOR
};

int				frac_err(int flag);
void			draw_mandel(t_mlx *set, t_frac mand);
void			draw_colors(t_mlx *set, t_frac mand);
void			mandel(t_mlx *set);
void			init_mandel(t_frac *mand);
int				mouse_func(int x, int y, void *param);
int				key_func(int keycode, void *param);

#endif
