/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:09:51 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/03 21:30:44 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calcul_values(t_draw_sprite *ds, t_cub *cub)
{
	ds->inv_det = 1.0 / (cub->plr->plane_x * cub->plr->dir_y
			- cub->plr->dir_x * cub->plr->plane_y);
	ds->transform_x = ds->inv_det * (cub->plr->dir_y * ds->sprite_x
			- cub->plr->dir_x * ds->sprite_y);
	ds->transform_y = ds->inv_det * (-cub->plr->plane_y * ds->sprite_x
			+ cub->plr->plane_x * ds->sprite_y);
	ds->sprite_screen_x = (int)((cub->width / 2) * (1 + ds->transform_x
				/ ds->transform_y));
	ds->sprite_height = abs((int)(cub->height / ds->transform_y));
	ds->draw_start_y = -ds->sprite_height / 2 + (cub->height / 2);
	if (ds->draw_start_y < 0)
		ds->draw_start_y = 0;
	ds->draw_end_y = ds->sprite_height / 2 + (cub->height / 2);
	if (ds->draw_end_y >= cub->height)
		ds->draw_end_y = cub->height - 1;
	ds->sprite_width = abs((int)(cub->height / ds->transform_y));
	ds->draw_start_x = -ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_start_x < 0)
		ds->draw_start_x = 0;
	ds->draw_end_x = ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_end_x >= cub->width)
		ds->draw_end_x = cub->width - 1;
	ds->stripe = ds->draw_start_x;
}

static void	pix_on_sprite_image(t_draw_sprite *ds, t_cub *cub)
{
	ds->d = ds->y * cub->texture[4]->width - cub->height
		* (cub->texture[4]->width / 2) + ds->sprite_height
		* cub->texture[4]->width / 2;
	ds->tex_y = ((ds->d * cub->texture[4]->height) / ds->sprite_height)
		/ cub->texture[4]->width;
	ds->totcolor = cub->texture[4]->data[ds->tex_y
		* cub->texture[4]->width + ds->tex_x]
		+ cub->texture[4]->data[ds->tex_y
		* cub->texture[4]->width + ds->tex_x]
		+ cub->texture[4]->data[ds->tex_y
		* cub->texture[4]->width + ds->tex_x];
	if (ds->totcolor)
		cub->screen->data[ds->y * cub->screen->width + ds->stripe] = \
		cub->texture[4]->data[ds->tex_y * cub->texture[4]->width + ds->tex_x];
}

static void	make_sprite(t_draw_sprite *ds, t_cub *cub, t_ray *ray)
{
	int	check;

	ds->sprite_x = ds->sprites[ds->i].x - (cub->plr->pos_x - 0.5);
	ds->sprite_y = ds->sprites[ds->i].y - (cub->plr->pos_y - 0.5);
	calcul_values(ds, cub);
	while (ds->stripe < ds->draw_end_x)
	{
		ds->tex_x = (int)(cub->texture[4]->width * (ds->stripe
					- (-ds->sprite_width / 2 + ds->sprite_screen_x))
				* cub->texture[4]->width / ds->sprite_width)
			/ cub->texture[4]->width;
		if (ds->transform_y > 0 && ds->stripe > 0 && ds->stripe
			< cub->width && ds->transform_y < ray->z_buff[ds->stripe])
		{
			ds->y = ds->draw_start_y;
			while (ds->y < ds->draw_end_y)
			{
				pix_on_sprite_image(ds, cub);
				ds->y++;
			}
		}
		ds->stripe++;
	}
}

void	draw_sprite(t_ray *ray, t_cub *cub)
{
	t_draw_sprite	*ds;

	ds = ft_calloc(sizeof(t_draw_sprite), 1);
	if (!ds)
		err_exit(2);
	ds->i = 0;
	ds->sprites = list_to_tab(cub);
	ds->i = ft_lstsize((t_list *)cub->sprites_on_screen);
	while (--ds->i >= 0)
		make_sprite(ds, cub, ray);
	free(ds->sprites);
}
