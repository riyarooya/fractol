/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:55 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/17 08:52:24 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list{
	unsigned long				i;
	unsigned int				k;
	char						c;
	char						*str;
	int							j;
	int							len;
}t_list;

char	ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		numprint(va_list args);
int		printstr(va_list args);
int		hexprint(va_list args, const char fmt);
int		print_u(va_list args);
int		p_print(va_list args);

#endif
