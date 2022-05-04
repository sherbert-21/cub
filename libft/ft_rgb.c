/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:23:10 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/04 08:34:48 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	rgb_to_int(int r, int g, int b)
{
	unsigned int	color;

	color = 256 * 256 * r + 256 * g + b;
	return(color);
}

int	*int_to_rgb(unsigned int color)
{
	int *clrs;

	clrs = ft_calloc(4, sizeof(int));
	if (!clrs)
		return (NULL);
	clrs[0] = color / (256 * 256);
	if (clrs[0] > 255)
		clrs[0] = 255;
	clrs[1] = (color / 256) % 256;
	if (clrs[1] > 255)
		clrs[1] = 255;
	clrs[2] = color % 256;
	if (clrs[2] > 255)
		clrs[2] = 255;
	return (clrs);
}

int	*clr_add(int *clr1, int *clr2)
{
	clr1[0] += clr2[0];
	if (clr1[0] > 255)
		clr1[0] = 255;
	clr1[1] += clr2[1];
	if (clr1[1] > 255)
		clr1[1] = 255;
	clr1[2] += clr2[2];
	if (clr1[2] > 255)
		clr1[2] = 255;
	return (clr1);
}