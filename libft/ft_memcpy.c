/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:21:05 by sherbert          #+#    #+#             */
/*   Updated: 2020/05/03 17:21:07 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*str;
	size_t	i;

	dst = (char*)dest;
	str = (char*)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dest);
}
