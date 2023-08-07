/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:04:07 by juhaamid          #+#    #+#             */
/*   Updated: 2023/08/07 10:32:27 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W_WIDTH 1250
# define W_HEIGHT 1250
# define MAX_ITERATION 65

# include "./mlx/mlx.h"
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

//******fractol-init.c*****//

int		fractol_check(char **av, t_pop *img);
int		fractolinit( t_pop *img);
void	lastjulia(t_pop *img);

//*******main.c*******//
void	my_mlx_pixel_put(t_pop *data, int x, int y, int color);
void	all_hooks(t_pop *img);
void	make_image(t_pop *img);

//******hooks.c//
int		closee( t_pop *img);
void	leftright(int code, t_pop *img);
int		keymove(int code, t_pop *img);
void	m_zoom(t_pop *img, float zoom, int x, int y);
int		umizoomi(int code, int x, int y, t_pop *img);

//********utils.c*********//
void	error_mess(void);
void	minint(t_pop *img);
void	set_minmax(t_pop *img);
void	help_controls(t_pop *i);
int		color(t_pop *f, int iterations);

//******julia.c******//
void	julia(t_pop *im);
int		is_julia(float zr, float zi, t_pop *im);

//******mandelbrot.c******//
void	mandelbrot(t_pop *im);
int		is_mandelbrot(float cr, float ci, t_pop *im);

int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);

#endif