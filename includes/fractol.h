/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/25 02:00:43 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include <OpenCL/opencl.h>
# include <sys/stat.h>
# include <stdio.h>

#define DEBUG fpf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			nbit;
	int			deca_nbit;
	int			line;
	int			endian;
}				t_mlx;

typedef struct	s_mlx_conv
{
	int			deca_nbit;
	int			line;
}				t_mlx_conv;

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

typedef struct	s_ocl
{
	cl_platform_id			plateform_id;
	cl_uint					plateform_count;
	cl_int					err;
	cl_device_id			device;
	cl_uint					device_count;
	cl_context				context;
	cl_context_properties	properties[3];
	cl_command_queue		cmd_queue;
	cl_program				prog;
	char					*src;
	size_t					src_size;
	cl_kernel				kernel;
	cl_mem					output;
	size_t					global_work_size;
	size_t					local_work_size;
}				t_ocl;

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
t_ocl			init_open_cl(void);

#endif
