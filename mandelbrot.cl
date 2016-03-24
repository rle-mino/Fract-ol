typedef struct  s_frac
{
	double      x1;
	double      y1;
	int         x;
	int         y;
	double      x2;
	double      y2;
	double      c_r;
	double      c_i;
	double      z_r;
	double      z_i;
	int         i;
	double      tmp;
	double      zoom_y;
	double      zoom_x;
	double      tmp_z_r;
	double      tmp_z_i;
	int         iter;
}               t_frac;

typedef struct  s_mlx
{
		int			nbit;
		int			deca_nbit;
		int			line;
		int			endian;
}				t_mlx;

static void			draw_colors(__global t_frac	*mand,
								__global t_mlx	*set,
								__global char	*img_data)
{
	size_t		index;

	index = mand->x * set->deca_nbit + (mand->y * set->line);
	if (mand->i == mand->iter)
	{
		img_data[index] = 255;
		img_data[index + 1] = 255;
		img_data[index + 2] = 255;
	}
	else
	{
		img_data[index] = 255;
		img_data[index + 1] = 255;
		img_data[index + 2] = mand->i * 255 / mand->iter;
	}
}

static void			adjust_mand_val(__global t_frac *mand)
{
	mand->c_r = mand->x / mand->zoom_x + mand->x1;
	mand->c_i = mand->y / mand->zoom_y + mand->y1;
	mand->z_r = mand->tmp_z_r;
	mand->z_i = mand->tmp_z_i;
	mand->i = 0;
}

__kernel void		fractal(__global t_frac		*mand,
							__global t_mlx		*set,
							__global char		*img_data)
{
	mand->i = mand->iter;
	mand->y = -1;
	while ((mand->y += 1) < 300)
	{
		mand->x = -1;
		while ((mand->x += 1) < 300)
			draw_colors(mand, set, img_data);
	}
/*	mand->x = -1;
	while (++mand->x < 1000)
	{
		mand->y = -1;
		while (++mand->y < 1000)
		{
			adjust_mand_val(mand);
			while (((mand->z_r * mand->z_r) + (mand->z_i * mand->z_i)) < 4 && mand->i < mand->iter)
			{
				mand->tmp = mand->z_r;
				mand->z_r = (mand->z_r * mand->z_r) - (mand->z_i * mand->z_i) + mand->c_r;
				mand->z_i = (2 * mand->z_i * mand->tmp) + mand->c_i;
				mand->i += 1;
			}
			draw_colors(mand, set, *img_data);
		}
	}*/
}
