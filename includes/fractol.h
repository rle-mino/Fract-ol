/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 13:01:05 by rle-mino         ###   ########.fr       */
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
	int			gpu;
	void		*img;
	char		*img_data;
	int			nbit;
	int			deca_nbit;
	int			line;
	int			endian;
	void		(*draw_fract)();
	char		*frac;
	int			id;
}				t_mlx;

typedef struct	s_frac
{
	double		x1;
	double		y1;
	int				x;
	int				y;
	double		x2;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int				i;
	double		tmp;
	double		zoom_y;
	double		zoom_x;
	double		tmp_z_r;
	double		tmp_z_i;
	int				iter;
}				t_frac;

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
	size_t					global_work_size[3];
	size_t					local_work_size;
}				t_ocl;

typedef struct	s_param
{
	t_frac		*mand;
	t_mlx		*set;
	int			mand_zoom;
	t_ocl		*ocl;
}				t_param;

enum
{
	ERRNO,
	USAGE,
	MALLOR
};

int				frac_err(int flag);
void			draw_mandel(t_mlx *set, t_frac mand);
void			draw_julia(t_mlx *set, t_frac jia);
void			draw_colors(t_mlx *set, t_frac mand);
void			fractal(t_mlx *set);
void			init_fract(t_frac *mand, t_mlx *set);
int				mouse_func_fract(int x, int y, void *param);
int				key_func_fract(int keycode, void *param);
int				zoom_func_fract(int button, int x, int y, void *param);
void			zoom_plus_fract(t_param *a, int x, int y);
void			zoom_min_fract(t_param *a, int x, int y);
t_ocl			*init_open_cl(t_mlx *set);
t_ocl			*draw_fract_opencl(t_mlx *set, t_frac mand);
void			*get_fract(char *fract);
void			get_frac_ocl(char *fract, t_mlx *set);
void			free_cl_ressources(t_ocl *ocl);

#endif
