/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:22 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/03 21:19:15 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture(t_cub *cub, int nbr)
{
	int	i;

	i = 0;
	cub->texture = malloc(sizeof(t_pic *) * nbr + 1);
	if (!cub->texture)
		return (err_exit(2));
	ft_bzero(cub->texture, sizeof(t_pic *));
	while (i < nbr)
	{
		cub->texture[i] = malloc(sizeof(t_pic));
		if (!cub->texture[i])
			return (err_exit(2));
		ft_bzero(cub->texture[i], sizeof(t_pic));
		i++;
	}
}

void	init_plr(t_cub *cub)
{
	cub->plr = malloc(sizeof(t_player));
	if (!cub->plr)
		err_exit(2);
	ft_bzero(cub->plr, sizeof(t_player));
	cub->plr->pos_x = -20.0;
	cub->plr->pos_y = -20.0;
	cub->plr->speed = 0.1;
	cub->plr->dir_x = 1.0;
	cub->plr->dir_y = 0.0;
	cub->plr->plane_x = -20.0;
	cub->plr->plane_y = -20.0;
	cub->plr->rotation = 0.1;
}

void	init_game_keybuffer(t_cub *cub)
{
	cub->keybuffer = malloc(sizeof(t_keybuffer));
	if (!cub->keybuffer)
		err_exit(2);
	ft_bzero(cub->keybuffer, sizeof(t_keybuffer));
	cub->keybuffer->forward = 0;
	cub->keybuffer->backward = 0;
	cub->keybuffer->left = 0;
	cub->keybuffer->right = 0;
	cub->keybuffer->turn_left = 0;
	cub->keybuffer->turn_right = 0;
}

int	init_game_sprite(t_cub *cub)
{
	cub->sprites_on_screen = malloc(sizeof(t_list));
	if (!cub->sprites_on_screen)
		err_exit(2);
	ft_bzero(cub->sprites_on_screen, sizeof(t_list));
	cub->sprites_on_screen->x = -1;
	cub->sprites_on_screen->y = -1;
	return (0);
}
