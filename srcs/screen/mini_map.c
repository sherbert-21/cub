/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:29:36 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/10 19:56:40 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color(unsigned int clr1, unsigned int clr2)
{
	int	*c1;
	int	*c2;
	unsigned int	clr;

	c1 = int_to_rgb(clr1);
	c2 = int_to_rgb(clr2);
	c1 = clr_add(c1, c2);
	c1[0] /= 2;
	c1[1] /= 2;
	c1[2] /= 2;
	clr = rgb_to_int(c1[0], c1[1], c1[2]);
	return(clr);
}

static void	draw_square(t_cub *cub, unsigned int color)
{
	int i;
	int	j;
	int step_x;
	int step_y;

	i = -1;
	step_x = cub->mini_map->step_x;
	step_y = cub->mini_map->step_y;
	while (++i <= cub->mini_map->pix)
	{
		j = -1;
		while (++j <= cub->mini_map->pix)
			cub->screen->data[(i + step_y) * cub->screen->width + (j + step_x)] = get_color(cub->screen->data[(i + step_y) * cub->screen->width + (j + step_x)], color);
	}
}

static unsigned int    set_color(int x, int y, t_map *map, t_cub *cub)
{
	unsigned int color;

	if (y == (int)cub->plr->pos_y && x == (int)cub->plr->pos_x && map->map[y][x] == 0)
		color = RED;
	else if (map->map[y][x] == 0)
        color = BLACK;
    else if (map->map[y][x] == 1)
        color = WHITE;
    color = BLUE;
	return (color);
}

void    draw_map(t_cub *cub, t_map *map)
{
    int x;
    int y;
	unsigned int color;
    
    y = -1;
	map->step_y = 0;
    while (++y < cub->map_y)
    {
        x = -1;
		map->step_x = 0;
        while (++x < cub->map_x)
        {
            color = set_color(x, y, map, cub);
			draw_square(cub, color);
			map->step_x += map->pix + 1;
        }
		map->step_y += map->pix + 1;
    }
}