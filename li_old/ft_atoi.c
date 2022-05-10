/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:16:32 by sherbert          #+#    #+#             */
/*   Updated: 2020/04/29 19:16:36 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(const char *str, int i, int sign)
{
	int k;
	int j;

	k = 0;
	j = i;
	while (str[j] >= 48 && str[j] <= 57 && str[j])
	{
		j++;
		k++;
	}
	if (k == 10 && (str[i] >= '3' || ft_strncmp(&str[i], "214748364", 9) == 0))
	{
		if (sign > 0 && (str[j] > '7' || str[i] >= '3'))
			return (-1);
		if (sign < 0 && (str[j] > '8' || str[i] >= '3'))
			return (0);
	}
	else if (k > 10 && sign > 0)
		return (-1);
	else if (k > 10 && sign < 0)
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int	nbr;
	int i;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] == 48)
		i++;
	if (ft_overflow(str, i, sign) == 0 || ft_overflow(str, i, sign) == -1)
		return (ft_overflow(str, i, sign));
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
