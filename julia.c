/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:28:45 by juhaamid          #+#    #+#             */
/*   Updated: 2023/08/07 12:56:17 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_julia(float zr, float zi, t_pop *im)
{
	float	tmp;
	int		i;

	i = 0;
	while (i++ <= MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4)
		{
			im->itera = i;
			return (im->itera);
		}
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + im->ci;
		zr = tmp + im->cr;
	}
	im->itera = i;
	return (0);
}

void	julia(t_pop *im)
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
			if (is_julia(pr, pi, im) == 0)
				my_mlx_pixel_put(im, x, y, 0x00000);
			else
				my_mlx_pixel_put(im, x, y, color(im, is_julia(pr, pi, im)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(im->mlx, im->win, im->img, 0, 0);
	return ;
}
