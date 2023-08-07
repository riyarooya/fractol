/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:06:39 by juhaamid          #+#    #+#             */
/*   Updated: 2023/08/07 13:41:56 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	my_mlx_pixel_put(t_pop *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->length + x * (data->blood_pressure / 8));
	*(unsigned int *)dst = color;
}

void	all_hooks(t_pop *img)
{
	mlx_mouse_hook(img->win, umizoomi, img);
	mlx_key_hook(img->win, keymove, img);
	mlx_hook(img->win, 17, 0, closee, img);
}

void	make_image(t_pop *img)
{
	img->img = mlx_new_image(img->mlx, W_WIDTH, W_HEIGHT);
	img->address = mlx_get_data_addr(img->img, &img->blood_pressure,
			&img->length, &img->endian);
}

int	main(int ac, char **av)
{
	t_pop	*img;

	if (ac != 2)
		error_mess();
	img = malloc(sizeof(t_pop));
	fractol_check(av, img);
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, W_WIDTH, W_HEIGHT,
			"juwairiyyah's fract-ol <3");
	make_image(img);
	set_minmax(img);
	fractolinit(img);
	mlx_loop(img->mlx);
	return (0);
}
