/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:36:44 by juhaamid          #+#    #+#             */
/*   Updated: 2023/07/31 14:42:51 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol_check(char **av, t_pop *img)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		img->fractal = ft_strdup(av[1]);
		return (0);
	}
	if (!ft_strcmp(av[1], "1stjulia"))
	{
		img->fractal = ft_strdup(av[1]);
		return (0);
	}
	if (!ft_strcmp(av[1], "2ndjulia") 
		|| !ft_strcmp(av[1], "3rdjulia"))
	{
		img->fractal = ft_strdup(av[1]);
		return (0);
	}
	else
	{
		free(img);
		error_mess();
	}
	return (1);
}

void	lastjulia(t_pop *img)
{
	if (!ft_strcmp(img->fractal, "3rdjulia"))
	{
		img->cr = 0.37;
		img->ci = 0.1;
		julia(img);
		help_controls(img);
	}
}

int	fractolinit( t_pop *img)
{
	all_hooks(img);
	mlx_clear_window(img->mlx, img->win);
	if (!ft_strcmp(img->fractal, "mandelbrot"))
	{
		mandelbrot(img);
		help_controls(img);
	}
	if (!ft_strcmp(img->fractal, "1stjulia"))
	{
		img->cr = -0.54;
		img->ci = 0.54;
		julia(img);
		help_controls(img);
	}
	if (!ft_strcmp(img->fractal, "2ndjulia"))
	{
		img->cr = -0.3842;
		img->ci = -0.70176;
		julia(img);
		help_controls(img);
	}
	else
		lastjulia(img);
	return (0);
}
