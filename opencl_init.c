/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:33:14 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/28 22:07:37 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		load_program_source(const char *filename, t_ocl *ocl)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	ocl->src = ft_memalloc(8196);
	ocl->src_size = read(fd, ocl->src, 8196);
	close(fd);
}

void		get_program(t_ocl *ocl, t_mlx *set)
{
	load_program_source(set->frac, ocl);
}

t_ocl		*init_open_cl(t_mlx *set)
{
	t_ocl	*ocl;

	ocl = (t_ocl *)malloc(sizeof(t_ocl));
	ocl->err = clGetPlatformIDs(1, &ocl->plateform_id, &ocl->plateform_count);
	ocl->err = clGetDeviceIDs(ocl->plateform_id, CL_DEVICE_TYPE_GPU, 1,
									&ocl->device, &ocl->device_count);
	ocl->properties[0] = CL_CONTEXT_PLATFORM;
	ocl->properties[1] = (cl_context_properties)ocl->plateform_id;
	ocl->properties[2] = 0;
	ocl->context = clCreateContext(ocl->properties, ocl->device_count,
			&ocl->device, NULL, NULL, &ocl->err);
	get_program(ocl, set);
	ocl->cmd_queue = clCreateCommandQueue(ocl->context,
						ocl->device, 0, &ocl->err);
	ocl->prog = clCreateProgramWithSource(ocl->context, 1,
			(const char **)&ocl->src, NULL, &ocl->err);
	ocl->err = clBuildProgram(ocl->prog, ocl->device_count, &ocl->device,
									NULL, NULL, NULL);
	ocl->kernel = clCreateKernel(ocl->prog, "fractal", &ocl->err);
	ocl->output = clCreateBuffer(ocl->context,
			CL_MEM_WRITE_ONLY,
			(1000 * set->line), NULL, &ocl->err);
	ocl->global_work_size[0] = 1000;
	ocl->global_work_size[1] = 1000;
	return (ocl);
}
