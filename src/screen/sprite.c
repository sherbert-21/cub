/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:10:36 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/03 22:14:49 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	next_sprite(t_sprites *actual, t_sprites *new, t_ray *ray)
// {
// 	while (1)
// 	{
// 		if (actual->x == ray->map_x && actual->y == ray->map_y)
// 		{
// 			free(new);
// 			break ;
// 		}
// 		if ((actual->x != ray->map_x || actual->y != ray->map_y)
// 			&& !actual->next)
// 		{
// 			actual->next = new;
// 			break ;
// 		}
// 		if (actual->next)
// 			actual = actual->next;
// 		else
// 		{
// 			free(new);
// 			break ;
// 		}
// 	}
// }

// void	is_sprite(t_ray *ray, t_cub *cub)
// {
// 	t_sprites	*new;
// 	t_sprites	*actual;
// 	t_sprites	save_top;

// 	new = malloc(sizeof(t_sprites));
// 	if (!new)
// 		err_exit(2);
// 	new->next = NULL;
// 	new->x = ray->map_x;
// 	new->y = ray->map_y;
// 	actual = cub->sprites_on_screen;
// 	save_top = *actual;
// 	if (actual->x == -1 && actual->y == -1)
// 	{
// 		actual->x = ray->map_x;
// 		actual->y = ray->map_y;
// 	}
// 	else
// 		next_sprite(actual, new, ray);
// 	actual = &save_top;
// }

// t_sprite	*list_to_tab(t_cub *cub)
// {
// 	t_sprite	*rtn;
// 	t_sprites	*save_top;
// 	int			count;

// 	save_top = cub->sprites_on_screen;
// 	count = -1;
// 	rtn = ft_calloc(sizeof(t_sprite), \
// 		ft_lstsize((t_list *)cub->sprites_on_screen));
// 	if (!rtn)
// 		err_exit(2);
// 	while (++count > -1)
// 	{
// 		if (cub->sprites_on_screen)
// 		{
// 			rtn[count].x = cub->sprites_on_screen->x;
// 			rtn[count].y = cub->sprites_on_screen->y;
// 		}
// 		if (cub->sprites_on_screen->next)
// 			cub->sprites_on_screen = cub->sprites_on_screen->next;
// 		else
// 			break ;
// 	}
// 	cub->sprites_on_screen = save_top;
// 	return (rtn);
// }

// void	is_sprite(t_ray *ray, t_cub *cub)
// {
// 	int i;

// 	i = cub->sprite_i;
// 	cub->sprite_order[i].x = ray->map_x;
// 	cub->sprite_order[i].y = ray->map_y;
// 	cub->sprite_order[i].distance = ((cub->plr->pos_x - cub->sprite_order[i].x) * (cub->plr->pos_x - cub->sprite_order[i].x) + (cub->plr->pos_y - cub->sprite_order[i].y) * (cub->plr->pos_y - cub->sprite_order[i].y));
// 	cub->sprite_i++;
// }
