/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:10:56 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/03 21:19:41 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	turn_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->plr->dir_x;
	old_plane_x = cub->plr->plane_x;
	cub->plr->dir_x = cub->plr->dir_x * cos(-cub->plr->rotation)
		- cub->plr->dir_y * sin(-cub->plr->rotation);
	cub->plr->dir_y = old_dir_x * sin(-cub->plr->rotation)
		+ cub->plr->dir_y * cos(-cub->plr->rotation);
	cub->plr->plane_x = cub->plr->plane_x * cos(-cub->plr->rotation)
		- cub->plr->plane_y * sin(-cub->plr->rotation);
	cub->plr->plane_y = old_plane_x * sin(-cub->plr->rotation)
		+ cub->plr->plane_y * cos(-cub->plr->rotation);
}

void	turn_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->plr->dir_x;
	old_plane_x = cub->plr->plane_x;
	cub->plr->dir_x = cub->plr->dir_x * cos(cub->plr->rotation)
		- cub->plr->dir_y * sin(cub->plr->rotation);
	cub->plr->dir_y = old_dir_x * sin(cub->plr->rotation)
		+ cub->plr->dir_y * cos(cub->plr->rotation);
	cub->plr->plane_x = cub->plr->plane_x * cos(cub->plr->rotation)
		- cub->plr->plane_y * sin(cub->plr->rotation);
	cub->plr->plane_y = old_plane_x * sin(cub->plr->rotation)
		+ cub->plr->plane_y * cos(cub->plr->rotation);
}
