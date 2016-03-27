/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:53:12 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/27 19:36:06 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		free_cl_ressources(t_ocl *ocl)
{
	clReleaseMemObject(ocl->output);
	clReleaseProgram(ocl->prog);
	clReleaseKernel(ocl->kernel);
	clReleaseCommandQueue(ocl->cmd_queue);
	clReleaseContext(ocl->context);
}

t_ocl		*draw_fract_opencl(t_mlx *set, t_frac mand)
{
	static t_ocl	*ocl = NULL;

	if (ocl == NULL)
		ocl = init_open_cl(set);
	ocl->err = clSetKernelArg(ocl->kernel, 0, sizeof(cl_mem), &ocl->output);
	ocl->err = clSetKernelArg(ocl->kernel, 1, sizeof(int), &set->deca_nbit);
	ocl->err = clSetKernelArg(ocl->kernel, 2, sizeof(int), &set->line);
	ocl->err = clSetKernelArg(ocl->kernel, 3, sizeof(double), &mand.zoom_x);
	ocl->err = clSetKernelArg(ocl->kernel, 4, sizeof(double), &mand.zoom_y);
	ocl->err = clSetKernelArg(ocl->kernel, 5, sizeof(double), &mand.x1);
	ocl->err = clSetKernelArg(ocl->kernel, 6, sizeof(double), &mand.y1);
	ocl->err = clSetKernelArg(ocl->kernel, 7, sizeof(double), &mand.tmp_z_r);
	ocl->err = clSetKernelArg(ocl->kernel, 8, sizeof(double), &mand.tmp_z_i);
	ocl->err = clSetKernelArg(ocl->kernel, 9, sizeof(int), &mand.iter);
	ocl->err = clEnqueueNDRangeKernel(ocl->cmd_queue, ocl->kernel, 2, NULL,
			ocl->global_work_size, NULL, 0, NULL, NULL);
	ocl->err = clFinish(ocl->cmd_queue);
	ocl->err = clEnqueueReadBuffer(ocl->cmd_queue, ocl->output,
			CL_TRUE, 0, (1000 * set->line), set->img_data, 0, NULL, NULL);
	return (ocl);
}

void		init_frac_set(t_mlx *set)
{
	set->img = mlx_new_image(set->mlx, 1000, 1000);
	set->img_data = mlx_get_data_addr(set->img, &set->nbit, &set->line,
															&set->endian);
	set->deca_nbit = set->nbit >> 3;
}

void		fractal(t_mlx *set)
{
	t_frac	mand;
	t_param	*param;

	if (!(param = (t_param *)ft_memalloc(sizeof(t_param))))
		frac_err(MALLOR);
	param->mand_zoom = 0;
	init_frac_set(set);
	param->set = set;
	init_fract(&mand);
	param->mand = &mand;
	if (set->gpu == 1)
		draw_fract_opencl(set, mand);
	else
		set->draw_fract(set, mand);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	mlx_hook(set->win, 2, 0, key_func_fract, param);
	mlx_hook(set->win, 4, 0, zoom_func_fract, param);
	mlx_hook(set->win, 6, 0, mouse_func_fract,  param);
	mlx_loop(set->mlx);
}
