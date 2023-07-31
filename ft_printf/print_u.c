/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:45:13 by juhaamid          #+#    #+#             */
/*   Updated: 2023/05/07 00:08:53 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

void	putunsign(unsigned int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10)
	{
		putunsign(n / 10);
		putunsign(n % 10);
	}
}

int	print_u(va_list args)
{
	t_list	var;

	var.k = va_arg(args, unsigned int);
	if (var.k == 0)
		return (write(1, "0", 1));
	else
	{
		putunsign(var.k);
			var.len = size(var.k);
	}
	return (var.len);
}
