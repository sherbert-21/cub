/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:16:13 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/03 22:01:21 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	valid_argc(int argc, char **argv)
{
	int	fd;

	if (argc != 2 && argc != 3)
		err_exit(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_exit(1);
}

void	valid_input(int argc, char **argv, t_cub *cub)
{
	int	i;

	cub->save_bmp = 0;
	valid_argc(argc, argv);
	i = (int)ft_strlen(argv[1]) - 1;
	if (argc == 2)
	{
		if (!(ft_strncmp(argv[1], "--save", ft_strlen("--save")))
			|| (argv[1][i - 3] != '.' || argv[1][i - 2] != 'c'
				|| argv[1][i - 1] != 'u' || argv[1][i] != 'b'))
			err_exit(0);
	}
	else if (argc == 3)
	{
		if (!(ft_strncmp(argv[1], "--save", ft_strlen("--save")))
			|| (argv[1][i - 3] != '.' || argv[1][i - 2] != 'c'
				|| argv[1][i - 1] != 'u' || argv[1][i] != 'b')
			|| ft_strncmp(argv[2], "--save", ft_strlen("--save")))
			err_exit(0);
		cub->save_bmp = 1;
	}
}
