/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:23 by sherbert          #+#    #+#             */
/*   Updated: 2022/02/08 16:25:47 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_int(int len, int *a)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_printf("%d\t", a[i]);
	ft_printf("\n");
}