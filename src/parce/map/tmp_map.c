/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:01:24 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/03 21:31:55 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	width_and_heigth_of_map(t_list *file, t_cub *cub)
{
	while (file)
	{
		if (cub->map_x < ft_strlen(file->content))
			cub->map_x = ft_strlen(file->content);
		cub->map_y++;
		file = file->next;
	}
}

char	**file_into_map(t_list *file, t_cub *cub)
{
	char	**tmp;
	char	*line;
	int		x;
	int		y;

	y = -1;
	width_and_heigth_of_map(file, cub);
	tmp = ft_calloc(cub->map_y + 1, sizeof(char *));
	if (!tmp)
		err_exit(2);
	while (++y < cub->map_y)
	{
		x = -1;
		tmp[y] = ft_calloc(cub->map_x + 1, sizeof(char));
		if (!tmp[y])
			err_exit(2);
		line = ft_strdup(file->content);
		while (line[++x])
			tmp[y][x] = line[x];
		while (x < cub->map_x)
			tmp[y][x++] = ' ';
		ft_lstdelone(file, save_free);
		file = file->next;
	}
	return (tmp);
}
