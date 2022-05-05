/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:10:13 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/05 18:24:33 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	sprite_value(t_cub *cub)
{
	int i;

	i = -1;
	while(++i < cub->sprites_num)
		cub->sprite_order[i].distance = ((cub->plr->pos_x - cub->sprite_order[i].x) * (cub->plr->pos_x - cub->sprite_order[i].x) + (cub->plr->pos_y - cub->sprite_order[i].y) * (cub->plr->pos_y - cub->sprite_order[i].y));
}

static void	next_step(t_ray *ray, t_player *plr)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (plr->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - plr->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (plr->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - plr->pos_y) * ray->delta_dist_y;
	}
}

static void	init_values(t_ray *ray, t_player *plr, t_cub *cub)
{
	int i;

	i = -1;
	ray->camera_x = (2 * ray->pix) / (double)cub->width - 1;
	ray->dir_x = plr->dir_x + plr->plane_x * ray->camera_x;
	ray->dir_y = plr->dir_y + plr->plane_y * ray->camera_x;
	ray->map_x = (int)plr->pos_x;
	ray->map_y = (int)plr->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
	sprite_value(cub);
}

static void	raycasting(t_cub *cub, t_ray *ray)
{
	t_player	*plr;

	plr = cub->plr;
	ray->pix = 0;
	while (ray->pix < cub->screen->width)
	{
		init_values(ray, plr, cub);
		next_step(ray, plr);
		hit(ray, cub);
		perp_and_height(ray, plr, cub);
		ray->z_buff[ray->pix] = ray->perp_wall_dist;
		texturisation(ray, cub);
		ray->pix++;
	}
}

int	ray(t_cub *cub)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	if (!ray)
		err_exit(2);
	ray->z_buff = ft_calloc(sizeof(double), cub->width);
	if (!ray->z_buff)
		err_exit(2);
	raycasting(cub, ray);
	draw_sprite(ray, cub);
	draw_map(cub, cub->mini_map);
	if (cub->save_bmp == 1)
	{
		create_bitmap(cub->screen, "cub3D.bmp");
		return (SUCCESS);
	}
	mlx_put_image_to_window(cub->mlx, cub->win,
		cub->screen->img, 0, 0);
	free(ray->z_buff);
	free(ray);
	return (SUCCESS);
}
