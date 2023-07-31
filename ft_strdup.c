/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:51:04 by juhaamid          #+#    #+#             */
/*   Updated: 2023/07/31 10:37:08 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		bop;

	bop = 0;
	while (s1[bop])
		bop++;
	dest = malloc(sizeof(char) * bop + 1);
	bop = 0;
	if (dest == NULL)
		return (NULL);
	else
	{
		while (s1[bop])
		{
			dest[bop] = s1[bop];
			bop++;
		}
		dest[bop] = '\0';
		return (dest);
	}
}
