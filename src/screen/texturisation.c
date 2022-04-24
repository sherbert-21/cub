/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:10:48 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/24 17:01:12 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_pic	*set_pic(t_cub *cub, int side)
{
	if (side == 1)
		return(cub->texture[1]);
	if (side == 2)
		return(cub->texture[2]);
	if (side == 3)
		return(cub->texture[3]);
	else
		return(cub->texture[0]);
}

static void	determine_side_draw(t_ray *ray, t_cub *cub,
								t_line *line, double wall_x)
{
	t_pic	*pic;
	int		tex_x;

	pic = set_pic(cub, ray->side);
	tex_x = (int)(wall_x * (double)pic->width);
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
	{
		tex_x = pic->width - tex_x - 1;
		ray->floor_x_wall = ray->map_x;
		ray->floor_y_wall = ray->map_y + wall_x;
	}
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x < 0)
		ray->floor_x_wall = ray->map_x + 1.0;
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y < 0)
	{
		tex_x = pic->width - tex_x - 1;
		ray->floor_x_wall = ray->map_x + wall_x;
        ray->floor_y_wall = ray->map_y + 1.0;
	}
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y > 0)
		ray->floor_y_wall = ray->map_y - 1.0;
	// if (ray->draw_end < 0)
	// 	ray->draw_end = cub->height;
	// line->y0 = ray->draw_end;
	// line->y1 = cub->height;
	// ver_floor_and_cell(line, cub, ray);
	line->y0 = ray->draw_end;
	line->y1 = ray->draw_start;
	line->tex_x = tex_x;
	ver_line_texture_pic(line, cub, pic, ray);
}

static void	draw_floor(t_ray *ray, t_cub *cub,
						t_line *line, double wall_x)
{
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
	{
		ray->floor_x_wall = ray->map_x;
		ray->floor_y_wall = ray->map_y + wall_x;
	}
    else if((ray->side == 0 || ray->side == 1) && ray->dir_x < 0)
    {
        ray->floor_x_wall = ray->map_x + 1.0;
		ray->floor_y_wall = ray->map_y + wall_x;
    }
    else if ((ray->side == 2 || ray->side == 3) && ray->dir_y > 0)
    {
        ray->floor_x_wall = ray->map_x + wall_x;
        ray->floor_y_wall = ray->map_y;
    }
    else
    {
        ray->floor_x_wall = ray->map_x + wall_x;
        ray->floor_y_wall = ray->map_y + 1.0;
    }
}

void	texturisation(t_ray *ray, t_cub *cub)
{
	t_line	*line;
	double	wall_x;

	line = ft_calloc(sizeof(t_line), 1);
	if (!line)
		err_exit(2);
	line->x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		wall_x = cub->plr->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = cub->plr->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	if (cub->map[ray->map_x][ray->map_y] == 1)
		determine_side_draw(ray, cub, line, wall_x);
	draw_floor(ray, cub, line, wall_x);
	if (ray->draw_end < 0)
		ray->draw_end = cub->height;
	ver_floor_and_cell(line, cub, ray);
}
