
__kernel void       fractal(__global char   *img_data,
		int             deca_nbit,
		int             line,
		double          zoom_x,
		double          zoom_y,
		double          x1,
		double          y1,
		double          tmp_z_r,
		double          tmp_z_i,
		int             iter)
{
	double  c_r;
	double  c_i;
	double  z_r;
	double  z_i;
	double  tmp;
	int     i = 0;
	int     index = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);

	c_r = x / zoom_x + x1;
	c_i = y / zoom_y + y1;
	z_r = tmp_z_r;
	z_i = tmp_z_i;
	while (((z_r * z_r) + (z_i * z_i)) < 4 && i < iter)
	{
		tmp = z_r * z_i;
		z_r = fabs((z_r * z_r) - (z_i * z_i)) + c_r;
		z_i = tmp + tmp + c_i;
		i++;
	}
	index = (x * deca_nbit) + (y * line);
	if (i == iter)
	{
		img_data[index] = 110;
		img_data[index + 1] = 110;
		img_data[index + 2] = 110;
	}
	else
	{
		img_data[index] = 50;
		img_data[index + 1] = 50;
		img_data[index + 2] = i * 255 / iter;
	}
}
