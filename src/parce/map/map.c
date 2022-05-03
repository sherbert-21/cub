/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:03:19 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/03 17:45:10 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include <stdio.h>

static void	symbol_int_map(char ch, int x, int y, t_cub *cub)
{
	if (ch >= '0' && ch <= '2')
		cub->mini_map->map[y][x] = ch - '0';
	else if (ch == ' ')
		cub->mini_map->map[y][x] = 0;
	else if (ft_strchr("NSWE", ch))
		cub->mini_map->map[y][x] = 0;
}

static void	symbol_int(char ch, int x, int y, t_cub *cub)
{
	if (ch >= '0' && ch <= '2')
		cub->map[y][x] = ch - '0';
	else if (ch == ' ')
		cub->map[y][x] = 1;
	else if (ft_strchr("NSWE", ch))
		cub->map[y][x] = 0;
}

static void	fill_mini_map(char **map, t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	cub->mini_map->map = ft_calloc(cub->map_y + 1, sizeof(int *));
	if (!cub->mini_map->map)
		err_exit(2);
	while (map[++y])
	{
		x = -1;
		cub->mini_map->map[y] = ft_calloc(cub->map_x + 1, sizeof(int));
		if (!cub->mini_map->map[y])
			err_exit(2);
		while (map[y][++x])
			symbol_int_map(map[y][x], x, y, cub);
	}
}

static void	char_to_int_map(char **map, t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	fill_mini_map(map, cub);
	cub->map = ft_calloc(cub->map_y + 1, sizeof(int *));
	if (!cub->map)
		err_exit(2);
	while (map[++y])
	{
		x = -1;
		cub->map[y] = ft_calloc(cub->map_x + 1, sizeof(int));
		if (!cub->map[y])
			err_exit(2);
		while (map[y][++x])
			symbol_int(map[y][x], x, y, cub);
		save_free(&map[y]);
	}
}

void	parce_map(t_list **file, t_cub *cub)
{
	char	**tmp_map;
	int		k;
	int		j;
	int		plr;

	j = 0;
	plr = -1;
	tmp_map = file_into_map(*file, cub);
	check_square(tmp_map, cub);
	while (++j < cub->map_y - 1)
	{
		k = 0;
		while (++k < cub->map_x - 1)
		{
			check_symbol(tmp_map, j, k, cub);
			if (ft_strchr("NSWE", tmp_map[j][k]))
			{
				set_dir(tmp_map[j][k], j, k, cub);
				plr++;
			}
		}
	}
	if (plr != 0)
		err_exit(11);
	char_to_int_map(tmp_map, cub);
}
