/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:15:30 by sherbert          #+#    #+#             */
/*   Updated: 2022/02/08 16:15:50 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_put_part_pointer(char *pointer, t_flags flags)
{
	int	char_count;

	char_count = 0;
	char_count += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(pointer), 1);
		char_count += ft_putstrprec(pointer, flags.dot);
	}
	else
		char_count += ft_putstrprec(pointer, ft_strlen(pointer));
	return (char_count);
}

int	ft_treat_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		char_count += ft_putstrprec("0x", 2);
		return (char_count += ft_treat_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_in_put_part_pointer(pointer, flags);
	char_count += ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}
