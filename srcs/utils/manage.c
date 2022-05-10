/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:57:34 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/10 18:07:13 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	ray(cub);
	move_events(cub);
	return (SUCCESS);
}

int	key_pressed(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (key == ESC)
		exit(0);
	else if (key == W && cub->keybuffer->forward == 0)
		cub->keybuffer->forward = 1;
	else if (key == S && cub->keybuffer->backward == 0)
		cub->keybuffer->backward = 1;
	else if (key == A && cub->keybuffer->left == 0)
		cub->keybuffer->left = 1;
	else if (key == D && cub->keybuffer->right == 0)
		cub->keybuffer->right = 1;
	else if (key == _LEFT && cub->keybuffer->turn_left == 0)
		cub->keybuffer->turn_left = 1;
	else if (key == _RIGHT && cub->keybuffer->turn_right == 0)
		cub->keybuffer->turn_right = 1;
	return (SUCCESS);
}

int	key_released(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if ((key == W) && cub->keybuffer->forward == 1)
		cub->keybuffer->forward = 0;
	else if ((key == S) && cub->keybuffer->backward == 1)
		cub->keybuffer->backward = 0;
	else if (key == A && cub->keybuffer->left == 1)
		cub->keybuffer->left = 0;
	else if (key == D && cub->keybuffer->right == 1)
		cub->keybuffer->right = 0;
	else if (key == _LEFT && cub->keybuffer->turn_left == 1)
		cub->keybuffer->turn_left = 0;
	else if (key == _RIGHT && cub->keybuffer->turn_right == 1)
		cub->keybuffer->turn_right = 0;
	return (0);
}

int	event_destroy_window(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	exit(0);
	return (SUCCESS);
}
