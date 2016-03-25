/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:39:11 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/25 03:17:27 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "assert.h"

t_mlx_conv	conv_set(t_mlx *set)
{
	t_mlx_conv	conv;

	conv.deca_nbit = set->deca_nbit;
	conv.line = set->line;
	return (conv);
}

void		free_cl_ressources(t_ocl ocl)
{
	clReleaseMemObject(ocl.output);
	clReleaseProgram(ocl.prog);
	clReleaseKernel(ocl.kernel);
	clReleaseCommandQueue(ocl.cmd_queue);
	clReleaseContext(ocl.context);
}

void		draw_mandel_opencl(t_mlx *set, t_frac mand)
{
	t_ocl		ocl;

	ocl = init_open_cl();
	(void)mand;
	ocl.global_work_size = 1000 * 1000;
	ocl.output = clCreateBuffer(ocl.context,
			CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR,
			1000 * set->line, set->img_data, &ocl.err);
	ocl.err = clSetKernelArg(ocl.kernel, 0, sizeof(int), &set->deca_nbit);
	ocl.err = clSetKernelArg(ocl.kernel, 1, sizeof(int), &set->line);
	ocl.err = clSetKernelArg(ocl.kernel, 2, sizeof(cl_mem), &ocl.output);
	ocl.err = clEnqueueNDRangeKernel(ocl.cmd_queue, ocl.kernel, 1, NULL,
				&ocl.global_work_size, NULL, 0, NULL, NULL);
	ocl.err = clEnqueueReadBuffer(ocl.cmd_queue, ocl.output,
			CL_TRUE, 0, 1000 * set->line, set->img_data, 0, NULL, NULL);
	free_cl_ressources(ocl);
}

void		init_mand_set(t_mlx *set)
{
	set->img = mlx_new_image(set->mlx, 1000, 1000);
	set->img_data = mlx_get_data_addr(set->img, &set->nbit, &set->line,
															&set->endian);
	set->deca_nbit = set->nbit >> 3;
}

void		mandel(t_mlx *set)
{
	t_frac	mand;
	t_param	*param;

	if (!(param = (t_param *)ft_memalloc(sizeof(t_param))))
		frac_err(MALLOR);
	param->mand_zoom = 0;
	init_mand_set(set);
	param->set = set;
	init_mandel(&mand);
	param->mand = &mand;
	//draw_mandel(set, mand);
	draw_mandel_opencl(set, mand);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	mlx_hook(set->win, 2, 0, key_func_mand, param);
	//mlx_hook(set->win, 4, 0, zoom_func_mand, param);
	//mlx_hook(set->win, 6, 0, mouse_func_mand, param);
	mlx_loop(set->mlx);
}
