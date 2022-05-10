/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:06:31 by rantario          #+#    #+#             */
/*   Updated: 2022/05/10 20:01:41 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
