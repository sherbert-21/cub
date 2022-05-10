/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:47:26 by sherbert          #+#    #+#             */
/*   Updated: 2022/05/10 18:07:04 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	data_to_bitmap(t_pic *img, int fd)
{
	int	i;
	int	*tmp_img;
	int	x;
	int	y;

	tmp_img = malloc(sizeof(int) * img->width * img->height);
	x = -1;
	while (++x < img->width)
	{
		y = img->height;
		while (--y >= 0)
			tmp_img[x + y * img->width] = \
				img->data[(img->width - x + 1) + y * img->width];
	}
	i = img->width * img->height;
	while (--i >= 0)
		write(fd, &tmp_img[i], 4);
	free(tmp_img);
	return (SUCCESS);
}

static int	bitmap_info_header(t_pic *img, int fd)
{
	int	header_info_size;
	int	plane_nbr;
	int	o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &img->width, 4);
	write(fd, &img->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &img->bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (SUCCESS);
}

int	create_bitmap(t_pic *img, char *name)
{
	int	fd;
	int	file_size;
	int	first_pix;

	fd = open(name, O_CREAT | O_RDWR, 0666);
	file_size = 14 + 40 + 4 + img->width * img->height * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(img, fd);
	data_to_bitmap(img, fd);
	close(fd);
	return (SUCCESS);
}
