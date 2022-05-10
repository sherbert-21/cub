/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:22 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/10 18:07:11 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mini_map(t_cub *cub)
{
	int	i;

	cub->mini_map = malloc(sizeof(t_map));
	if (!cub->mini_map)
		err_exit(2);
	ft_bzero(cub->mini_map, sizeof(t_map));
	i = 0;
	if (cub->map_x < cub->map_y)
	{
		while (i * cub->map_x < cub->width / 100 * 10)
			i++;
	}
	else
	{
		while (i * cub->map_y < cub->height / 100 * 10)
			i++;
	}
	cub->mini_map->height = cub->map_y * i;
	cub->mini_map->width = cub->map_x * i;
	cub->mini_map->pix = i;
	cub->mini_map->step_x = 0;
	cub->mini_map->step_y = 0;
}

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
	int i;
	int k;
	int j;

	i = 0;
	cub->sprite_order = ft_calloc(cub->sprites_num + 1, sizeof(t_sprite));
	if (!cub->sprite_order)
		err_exit(2);
	k = -1;
	while(++k < cub->map_y)
	{
		j = -1;
		while(++j < cub->map_x)
		{
			if (cub->mini_map->map[k][j] == 2)
			{
				cub->sprite_order[i].x = j;
				cub->sprite_order[i].y = k;
				cub->sprite_order[i].distance = -1;
				i++;
			}
		}
	}
	return (0);
}
