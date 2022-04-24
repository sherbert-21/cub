/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:10:02 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/03 21:28:11 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	left(t_cub *cub)
{
	if (cub->map[(int)(cub->plr->pos_x - cub->plr->plane_x
			* cub->plr->speed)][(int)cub->plr->pos_y] == 0)
		cub->plr->pos_x -= cub->plr->plane_x * cub->plr->speed;
	if (cub->map[(int)cub->plr->pos_x][(int)(cub->plr->pos_y
		- cub->plr->plane_y * cub->plr->speed)] == 0)
		cub->plr->pos_y -= cub->plr->plane_y * cub->plr->speed;
}

static void	right(t_cub *cub)
{
	if (cub->map[(int)(cub->plr->pos_x + cub->plr->plane_x * \
			cub->plr->speed)][(int)cub->plr->pos_y] == 0)
		cub->plr->pos_x += cub->plr->plane_x * cub->plr->speed;
	if (cub->map[(int)cub->plr->pos_x][(int)(cub->plr->pos_y + \
			cub->plr->plane_y * cub->plr->speed)] == 0)
		cub->plr->pos_y += cub->plr->plane_y * cub->plr->speed;
}

static void	forward(t_cub *cub)
{
	if (cub->map[(int)(cub->plr->pos_x + cub->plr->dir_x
			* cub->plr->speed)][(int)cub->plr->pos_y] == 0)
		cub->plr->pos_x += cub->plr->dir_x * cub->plr->speed;
	if (cub->map[(int)cub->plr->pos_x][(int)(cub->plr->pos_y
		+ cub->plr->dir_y * cub->plr->speed)] == 0)
		cub->plr->pos_y += cub->plr->dir_y * cub->plr->speed;
}

static void	backward(t_cub *cub)
{
	if (cub->map[(int)(cub->plr->pos_x - cub->plr->dir_x
			* cub->plr->speed)][(int)cub->plr->pos_y] == 0)
		cub->plr->pos_x -= cub->plr->dir_x * cub->plr->speed;
	if (cub->map[(int)cub->plr->pos_x][(int)(cub->plr->pos_y
		- cub->plr->dir_y * cub->plr->speed)] == 0)
		cub->plr->pos_y -= cub->plr->dir_y * cub->plr->speed;
}

int	move_events(t_cub *cub)
{
	if (cub->keybuffer->left == 1)
		left(cub);
	else if (cub->keybuffer->right == 1)
		right(cub);
	else if (cub->keybuffer->turn_left == 1)
		turn_left(cub);
	else if (cub->keybuffer->turn_right == 1)
		turn_right(cub);
	else if (cub->keybuffer->forward == 1)
		forward(cub);
	else if (cub->keybuffer->backward == 1)
		backward(cub);
	else if (cub->keybuffer->left == 1)
		left(cub);
	else if (cub->keybuffer->right == 1)
		right(cub);
	return (SUCCESS);
}
