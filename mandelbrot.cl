/*typedef struct  s_frac
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


static void			draw_colors(__global t_frac	*mand,
								__global int	*deca_nbit,
								__global int	*line;
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
}*/

__kernel void		fractal(int	deca_nbit,
							int	line,
							__global char	*img_data)
{
	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;
	double	zoom_x = 1000 / (x2 - x1);
	double	zoom_y = 1000 / (y2 - y1);
	int		max_iter = 100;
	double	c_r = 0;
	double	c_i = 0;
	double	z_r = 0;
	double	z_i = 0;
	double	tmp = 0;
	int		i = 0;
	int		index = 0;
	int		x = 0;
	int		y = 0;
	
	x = -1;
	while (++x < 1000)
	{
		y = -1;
		while (++y < 1000)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < max_iter)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * z_i * tmp) + c_i;
				i++;
			}
			index = (x * deca_nbit) + (y * line);
			if (i == max_iter)
			{
				img_data[index] = 0;
				img_data[index + 1] = 0;
				img_data[index + 2] = 0;
			}
			else
			{
				img_data[index] = 0;
				img_data[index + 1] = 0;
				img_data[index + 2] = i * 255 / max_iter;
			}
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	/*mand->x = 0;
	while (mand->x < 1000)
	{
		mand->y = 0;
		while (mand->y < 1000)
		{
			adjust_mand_val(mand);
			while (((mand->z_r * mand->z_r) + (mand->z_i * mand->z_i)) < 4 && mand->i < mand->iter)
			{
				mand->tmp = mand->z_r;
				mand->z_r = (mand->z_r * mand->z_r) - (mand->z_i * mand->z_i) + mand->c_r;
				mand->z_i = (2 * mand->z_i * mand->tmp) + mand->c_i;
				mand->i += 1;
			}
			mand->y++;
			draw_colors(mand, set, *img_data);
		}
		mand->x++;
	}*/
