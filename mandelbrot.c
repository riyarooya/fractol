/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:15:55 by juhaamid          #+#    #+#             */
/*   Updated: 2023/08/07 10:16:40 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Zn + 1 = Zn^2 + c
// Z0 = 1
// z1 = 1^2 +1 = 2
// z2 = 2^2 + 1 = 5
// https://complex-analysis.com/content/mandelbrot_set.html

int	is_mandelbrot(float cr, float ci, t_pop *im)
{
	float	zr;
	float	zi;
	float	tmp;
	int		i;

	im->itera = 0;
	i = 0;
	zr = 0;
	zi = 0;
	while (i <= MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			im->itera = i;
			return (im->itera);
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		i++;
	}
	im->itera = i;
	return (0);
}

void	mandelbrot(t_pop *im)
{
	int		x;
	int		y;
	float	pr;
	float	pi;

	y = 0;
	while (y < W_WIDTH)
	{
		pi = im->max_ima + ((float)y * (im->min_ima - im->max_ima) / W_HEIGHT);
		x = 0;
		while (x < W_HEIGHT)
		{
			pr = im->min_re + ((float)x * (im->max_re - im->min_re) / W_WIDTH);
			if (is_mandelbrot(pr, pi, im) == 0)
				my_mlx_pixel_put(im, x, y, 0x00000);
			else
				my_mlx_pixel_put(im, x, y,
					color(im, is_mandelbrot(pr, pi, im)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(im->mlx, im->win, im->img, 0, 0);
	return ;
}

// function defines placement plus color of pixel
// max ima is the max place the imaginary pixel aka y can be 
// both min ima (Y) and min_Re (X) are -2 aka some kind of a starting point
