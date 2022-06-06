/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:31:22 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/21 20:08:48 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	int	i;
	int	k;

	k = 0;
	if (*l == '\0')
		return ((char *)b);
	while (b[k] != '\0' && len > (size_t)k)
	{
		i = 0;
		if (b[k] == l[i])
		{
			while (b[k + i] == l[i] && b[k + i] && l[i]
				&& (size_t)(k + i) < len)
				i++;
			if (l[i] == '\0')
				return ((char *)&b[k]);
		}
		k++;
	}
	return (NULL);
}
