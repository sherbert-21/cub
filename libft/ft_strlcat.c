/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:21:01 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/21 20:10:50 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	k;
	size_t	lendest;
	size_t	lensrc;

	i = 0;
	k = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (nb <= lendest)
		return (lensrc + nb);
	while ((dest[i] != '\0') && (i < (nb - 1)))
		i++;
	while ((src[k] != '\0') && (i < (nb - 1)))
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (lendest + lensrc);
}
