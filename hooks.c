/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:51:34 by juhaamid          #+#    #+#             */
/*   Updated: 2023/08/07 12:33:46 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closee( t_pop *img)
{
	mlx_destroy_window(img->mlx, img->win);
	free(img->fractal);
	free(img);
	ft_printf("BYEEE!");
	exit(EXIT_FAILURE);
	return (0);
}

void	leftright(int code, t_pop *img)
{
	if (code == LEFT)
	{
		img->max_re -= img->mid_r * 0.1;
		img->min_re -= img->mid_r * 0.1;
	}
	if (code == RIGHT)
	{
		img->max_re += img->mid_r * 0.1;
		img->min_re += img->mid_r * 0.1;
	}
	if (code == ESC)
		closee(img);
}

int	keymove(int code, t_pop *img)
{
	img->mid_i = img->max_ima - img->min_ima;
	img->mid_r = img->max_re - img->min_re;
	if (code == UP)
	{
		img->max_ima += img->mid_i * 0.1;
		img->min_ima += img->mid_i * 0.1;
	}
	if (code == DOWN)
	{
		img->max_ima -= img->mid_i * 0.1;
		img->min_ima -= img->mid_i * 0.1;
	}
	if (code == LEFT || code == RIGHT || code == ESC)
		leftright(code, img);
	fractolinit(img);
	return (0);
}

void	m_zoom(t_pop *img, float zoom, int x, int y)
{
	(void)x;
	(void)y;
	img->mid_r = img->min_re - img->max_re;
	img->mid_i = img->max_ima - img->min_ima;
	img->max_re = img->max_re + (img->mid_r - zoom * img->mid_r) / 2;
	img->min_re = img->max_re + zoom * img->mid_r;
	img->min_ima = img->min_ima + (img->mid_i - zoom * img->mid_i) / 2;
	img->max_ima = img->min_ima + zoom * img->mid_i;
	return ;
}

int	umizoomi(int code, int x, int y, t_pop *img)
{
	(void)x;
	(void)y;
	if (code == 5)
	{
		m_zoom(img, 1.1, x, y);
	}
	if (code == 4)
		m_zoom(img, 0.9, x, y);
	fractolinit(img);
	return (0);
}
