/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:18:13 by juhaamid          #+#    #+#             */
/*   Updated: 2022/11/17 08:52:43 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *s)
{
	int	pop;

	pop = 0;
	while (s[pop] != '\0')
	{
		ft_putchar(s[pop]);
		pop++;
	}
	return (pop);
}

int	printstr(va_list args)
{
	t_list	pop;

	pop.str = va_arg(args, char *);
	if (pop.str == 0)
		return (write(1, "(null)", 6));
	else
		pop.len = ft_putstr(pop.str);
	return (pop.len);
}
