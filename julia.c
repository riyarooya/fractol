/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:28:45 by juhaamid          #+#    #+#             */
/*   Updated: 2023/07/26 23:18:04 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	is_julia(double zr, double zi, t_pop	*f)
{
	double	tmp;
	int		i;

	i = 0;
	while (i++ < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			f->itera = i;
			return (f->itera);
		}
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + f->cr;
		zr = tmp + f->ci;
	}
		f->itera = i;
	return (1);
}

void	julia(t_pop *f)
{
	int		x;
	int		y;
	float	pr;
	float	pi;

	y = 0;
	while (y < W_WIDTH)
	{
		pi = f->max_ima + ((float)y * (f->min_ima - f->max_ima) / W_HEIGHT);
		x = 0;
		while (x < W_HEIGHT)
		{
			pr = f->min_re + ((float)x * (f->max_re - f->min_re) / W_WIDTH);
			if (is_julia(pr, pi, f) == 0)
				my_mlx_pixel_put(f, x, y, 0x00000);
			else
				my_mlx_pixel_put(f, x, y, color(f, is_julia(pr, pi, f)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return ;
}

