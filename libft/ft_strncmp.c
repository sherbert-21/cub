/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 10:28:56 by sherbert          #+#    #+#             */
/*   Updated: 2020/05/02 10:28:59 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (i < len)
	{
		if (*cs1 == *cs2 && (*cs1 != '\0' || *cs2 != '\0'))
		{
			i++;
			cs1++;
			cs2++;
		}
		else
			return (*cs1 - *cs2);
	}
	return (0);
}
