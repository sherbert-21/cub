/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:59:40 by sherbert          #+#    #+#             */
/*   Updated: 2020/05/01 17:59:43 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	while (i-- >= 0)
	{
		if (*str == c)
			return ((char*)str);
		str--;
	}
	return (NULL);
}
