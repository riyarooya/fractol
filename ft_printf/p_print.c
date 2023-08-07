/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:32:08 by juhaamid          #+#    #+#             */
/*   Updated: 2023/08/07 09:56:36 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptrlen(unsigned long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

void	ptr_hex(unsigned long n)
{
	if (n >= 16)
	{
		ptr_hex(n / 16);
		ptr_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	p_print(va_list args)
{
	t_list	pop;

	pop.len = 0;
	pop.i = va_arg(args, unsigned long);
	if (pop.i == 0)
		return (write(1, "0x0", 3));
	else
	{
		pop.len = write(1, "0x", 2);
		ptr_hex(pop.i);
		pop.len += ptrlen(pop.i);
	}
	return (pop.len);
}
