/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:20:13 by sherbert          #+#    #+#             */
/*   Updated: 2022/04/03 21:33:30 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	get_clr(char *ident, int *i, t_cub *cub)
{
	int	clr;
	int	j;

	j = (int)*i;
	if (ident[j] == '\0')
		err_exit(8);
	clr = ft_atoi(&ident[j]);
	if (clr < 0 || clr > 255)
		err_exit(8);
	while (ft_isdigit(ident[j]))
		j++;
	if (ident[j] == ',')
	{
		if (ident[j + 1] == ',')
			err_exit(8);
		j++;
	}
	*i = j;
	return (clr);
}

static int	get_rgb(int r, int g, int b, char i)
{
	int	clr;

	clr = r;
	clr = (clr << 8) + g;
	clr = (clr << 8) + b;
	if (i == 'c')
		ft_putendl_fd("\t\tOK", 1);
	else
		ft_putendl_fd("\t\t\tOK", 1);
	return (clr);
}

void	color(char *ident, t_cub *cub)
{
	char	first_c;
	int		r;
	int		g;
	int		b;
	int		i;

	first_c = ident[0];
	i = 2;
	while (ident[i] == ' ')
		i++;
	r = get_clr(ident, &i, cub);
	while (ident[i] == ' ')
		i++;
	g = get_clr(ident, &i, cub);
	while (ident[i] == ' ')
		i++;
	b = get_clr(ident, &i, cub);
	while (ident[i] == ' ' || ident[i] == '\n')
		i++;
	if (ident[i] != '\0')
		err_exit(8);
	if (first_c == 'C')
		cub->clr_ceilling = get_rgb(r, g, b, 'c');
	else
		cub->clr_floor = get_rgb(r, g, b, 'f');
}
