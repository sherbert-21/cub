/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:12:43 by sherbert          #+#    #+#             */
/*   Updated: 2020/11/09 16:12:46 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *lst_new;

	if (*lst == NULL)
		*lst = new;
	else if (*lst && new)
	{
		lst_new = ft_lstlast(*lst);
		lst_new->next = new;
	}
}
