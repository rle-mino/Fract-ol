/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/18 21:03:38 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

# define MAX_ITER 50
#define DEBUG fpf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			nbit;
	int			line;
	int			endian;
	double		z_r;
	double		z_i;
	double		mand_zoom_x;
	double		mand_zoom_y;
	double		mand_deca_x;
	double		mand_deca_y;
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
	int			mand_zoom;
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
void			init_mandel(t_frac *mand, t_mlx *set);
int				mouse_func_mand(int x, int y, void *param);
int				key_func_mand(int keycode, void *param);
int				zoom_func_mand(int button, int x, int y, void *param);

#endif
