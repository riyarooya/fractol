/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:46:40 by juhaamid          #+#    #+#             */
/*   Updated: 2023/08/01 14:58:39 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_mess(void)
{
	ft_printf(PURPLE"TRY: ./fractol <TYPE>\n");
	ft_printf(PURPLE"FRACTAL TYPES:\n");
	ft_printf("---> mandelbrot <---\n");
	ft_printf("---> 1stjulia <---\n");
	ft_printf("---> 2ndjulia <---\n");
	ft_printf("---> 3rdjulia <---\n");
	exit(EXIT_FAILURE);
}

void	minint(t_pop *img)
{
	img->mid_r = 0;
	img->mid_i = 0;
	img->min_re = 0;
	img->max_re = 0;
	img->min_ima = 0;
	img->max_ima = 0;
	img->cr = 0;
	img->ci = 0;
}

void	set_minmax(t_pop *img)
{
	minint(img);
	img->min_re = -2;
	img->max_re = img->min_re * -1 * W_WIDTH / W_HEIGHT;
	img->min_ima = -2;
	img->max_ima = img->min_ima * -1 * W_HEIGHT / W_WIDTH;
	return ;
}

void	help_controls(t_pop *i)
{
	mlx_string_put(i->mlx, i->win, 45, 30, 0x00000, "CONTROLS :)");
	mlx_string_put(i->mlx, i->win, 30, 60, 0x00000, "QUIT       :   ESC");
	mlx_string_put(i->mlx, i->win, 30, 80,
		0x00000, "ZOOM IN    :   SCROLL DOWN");
	mlx_string_put (i->mlx, i->win, 30, 100,
		0x00000, "ZOOM OUT   :   SCROLL UP");
	mlx_string_put(i->mlx, i->win, 30, 120,
		0x00000, "MOVE UP    :   ARROW UP");
	mlx_string_put(i->mlx, i->win, 30, 140,
		0x00000, "MOVE DOWN  :   ARROW DOWN");
	mlx_string_put(i->mlx, i->win, 30, 160,
		0x00000, "MOVE LEFT  :   ARROW LEFT");
	mlx_string_put(i->mlx, i->win, 30, 180,
		0x00000, "MOVE RIGHT :   ARROW RIGHT");
}

int	color(t_pop *f, int iterations)
{
	(void)f;
	if (iterations == MAX_ITERATION)
		return (0x00000);
	else
		return (0x87ceff * iterations / 0.3);
	return (0);
}
