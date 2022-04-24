/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:16:45 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/25 01:38:54 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static void	init_null(t_cub *cub)
{
	cub->plr = NULL;
	cub->ray = NULL;
	cub->texture = NULL;
	cub->screen = NULL;
	cub->sprites_on_screen = NULL;
	cub->keybuffer = NULL;
}

static t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		err_exit(2);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ERR);
	cub->width = 400;
	cub->height = 0;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->save_bmp = 0;
	return (cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = init_cub();
	init_texture(cub, 7);
	init_plr(cub);
	init_game_sprite(cub);
	init_game_keybuffer(cub);
	init_mini_map(cub);
	file_parce(argc, argv, cub);
	cub->screen = new_pic(cub, cub->width, cub->height);
	if (cub->save_bmp == 1)
		ray(cub);
	if (cub->save_bmp == 0)
	{
		cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
		if (!cub->win)
			err_exit(2);
		mlx_hook(cub->win, 2, 1L << 0, key_pressed, cub);
		mlx_hook(cub->win, 3, 1L << 1, key_released, cub);
		mlx_hook(cub->win, 17, 1L << 17, event_destroy_window, cub);
		mlx_loop_hook(cub->mlx, loop, cub);
		mlx_loop(cub->mlx);
	}
	return (0);
}
