/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:41:37 by juhaamid          #+#    #+#             */
/*   Updated: 2023/05/07 00:07:49 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fmttcheck(const char *fmt, va_list args, int idx)
{
	t_list	pop;

	if (fmt[idx] == '%')
		pop.len = write(1, "%", 1);
	if (fmt[idx] == 'c')
	{
		pop.c = va_arg(args, int);
		pop.len = write(1, &pop.c, 1);
	}
	if (fmt[idx] == 'd' || fmt[idx] == 'i')
		pop.len = numprint(args);
	if (fmt[idx] == 's')
	{
		idx++;
		pop.len = printstr(args);
	}
	if (fmt[idx] == 'x' || fmt[idx] == 'X')
		pop.len = hexprint(args, fmt[idx]);
	if (fmt[idx] == 'u')
		pop.len = print_u(args);
	if (fmt[idx] == 'p')
		pop.len = p_print(args);
	return (pop.len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	va_list	args;

	va_start(args, format);
	idx = 0;
	len = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			idx++;
			len += fmttcheck(format, args, idx);
		}
		else
		{
			len += write(1, &format[idx], 1);
			idx++;
		}
	}
	va_end(args);
	return (len);
}
