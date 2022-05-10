/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:17:23 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/10 17:12:29 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_resolution(char *ident, char c, t_cub *cub)
{
	if (c == 'x')
	{
		cub->width = ft_atoi(ident);
		if (cub->width > 1920)
			cub->width = 1920;
	}
	else
	{
		cub->height = ft_atoi(ident);
		if (cub->height > 1080)
			cub->height = 1080;
	}
}

void	resolution(char *ident, t_cub *cub)
{
	while (*ident == ' ')
		ident++;
	set_resolution(ident, 'x', cub);
	while (ft_isdigit(*ident))
		ident++;
	while (*ident == ' ')
		ident++;
	if (*ident == '\0')
		err_exit(6);
	set_resolution(ident, 'y', cub);
	while (ft_isdigit(*ident))
		ident++;
	while (*ident == ' ' || *ident == '\n')
		ident++;
	if (*ident != '\0')
		err_exit(6);
	ft_putendl_fd("\t\t\tOK", 1);
	cub->plr->pos_z = 0.5 * cub->height;
}
