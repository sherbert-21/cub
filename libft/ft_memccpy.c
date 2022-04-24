/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:56:57 by sherbert          #+#    #+#             */
/*   Updated: 2020/05/03 18:56:59 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char*)d;
	src = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		*dest = *src;
		if (*dest == (unsigned char)c)
		{
			dest++;
			return (dest);
		}
		i++;
		dest++;
		src++;
	}
	return (NULL);
}
