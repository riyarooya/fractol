/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:25:53 by nuhaamid          #+#    #+#             */
/*   Updated: 2023/08/07 09:56:19 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sizehex(unsigned int n)
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

void	find_hex(unsigned int n, const char fmt)
{
	if (n >= 16)
	{
		find_hex(n / 16, fmt);
		find_hex(n % 16, fmt);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (fmt == 'x')
				ft_putchar(n - 10 + 'a');
			if (fmt == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	hexprint(va_list args, const char fmt)
{
	t_list	pop;

	pop.k = va_arg(args, unsigned int);
	if (pop.k == 0)
		return (write(1, "0", 1));
	else
	{
		find_hex(pop.k, fmt);
		pop.len = sizehex(pop.k);
	}
	return (pop.len);
}
// 10 to 15 minus 10 which gives 0 to 5 in ascii 
// then u add 'a' or 'A' to give corresponding letter
// so 13 - 10 is 3 then add 65 which will be 68 or D