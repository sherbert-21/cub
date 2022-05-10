/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 01:59:22 by sherbert          #+#    #+#             */
/*   Updated: 2020/05/18 01:59:23 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int count;

	count = 0;
	if (lst)
	{
		count = 1;
		while (lst->next)
		{
			count++;
			lst = lst->next;
		}
	}
	return (count);
}
