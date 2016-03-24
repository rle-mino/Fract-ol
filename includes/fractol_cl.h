/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/21 23:27:52 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 42
#define DEBUG fpf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*program_source;
	char		*img_data;
	int			nbit;
	int			deca_nbit;
	int			line;
	int			endian;
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
	double		tmp_z_r;
	double		tmp_z_i;
	int			iter;
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
void			init_mandel(t_frac *mand);
int				mouse_func_mand(int x, int y, void *param);
int				key_func_mand(int keycode, void *param);
int				zoom_func_mand(int button, int x, int y, void *param);
void			zoom_plus_mand(t_param *a, int x, int y);
void			zoom_min_mand(t_param *a, int x, int y);
void			init_open_cl(t_mlx *set);

#endif
