/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:04:07 by juhaamid          #+#    #+#             */
/*   Updated: 2023/07/31 14:59:23 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 
# define W_WIDTH 1250
# define W_HEIGHT 1250
# define MAX_ITERATION 100

# include "./mlx/mlx.h"
// # include "./mlx_linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <math.h>
# include <stddef.h>

typedef struct s_pop
{
	void			*img;
	char			*address;
	int				blood_pressure;
	int				length;
	int				endian;
	void			*mlx;
	void			*win;
	char			*fractal;
	float			x;
	float			y;
	float			re;
	float			ima;
	float			min_re;
	float			max_re;
	float			min_ima;
	float			max_ima;
	float			mid_i;
	float			mid_r;
	float			cr;
	float			ci;
	float			magnify;
	unsigned int	itera;	
	int				color;	
}t_pop;

# define PURPLE	"\033[0;35m"

# ifdef __APPLE__
#  define ESC	53
#  define UP		126
#  define DOWN	125
#  define RIGHT	124
#  define LEFT	123
#  define ON_MOUSE_DW 4

# else
#  define ESC	65307
#  define MOUSE_UP 4
#  define MOUSE_DOWN 5
#  define UP	65362
#  define DOWN	65364
#  define RIGHT	65363
#  define LEFT 65361
#  define ON_MOUSE_DW 4
# endif

int		fractol_check(char **av, t_pop *img);
int		fractolinit( t_pop *img);
void	my_mlx_pixel_put(t_pop *data, int x, int y, int color);
void	error_mess(void);
int		ft_strcmp(char *s1, char *s2);
void	mandelbrot(t_pop *f);

char	*ft_strdup(const char *s1);

void	set_minmax(t_pop *img);

void	minint(t_pop *img);
void	error_mess(void);
void	all_hooks(t_pop *img);
int		color(t_pop *f, int iterations);
int		fractolinit( t_pop *img);
void	help_controls(t_pop *i);
int		keymove(int code, t_pop *img);
void	m_zoom(t_pop *img, float zoom, int x, int y);
int		umizoomi(int code, int x, int y, t_pop *img);
void	julia(t_pop *f);
int		closee( t_pop *img);

#endif