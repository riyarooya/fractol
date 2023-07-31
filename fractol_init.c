/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:36:44 by juhaamid          #+#    #+#             */
/*   Updated: 2023/07/26 23:27:59 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"


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
		return(0);
	}
	if (!ft_strcmp(av[1], "2ndjulia"))
	{
		img->fractal = ft_strdup(av[1]);
		return (0);
	}
	return (1);
}

int	fractolinit( t_pop *img)
{
	all_hooks(img);
	if (!ft_strcmp(img->fractal, "mandelbrot"))
	{
		mandelbrot(img);
        help_controls(img);
	}
	if (!ft_strcmp(img->fractal, "1stjulia"))
	{
		img->cr = -0.2321;
		img->ci = -0.835;
		julia(img);
		help_controls(img);
		
	}
	if (!ft_strcmp(img->fractal, "2ndjulia"))
	{
		img->cr =-0.3842;
		img->ci = -0.70176;
		julia(img);
		help_controls(img);
		
	}
	return (0);
}
