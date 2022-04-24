/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:14:44 by sherbert          #+#    #+#             */
/*   Updated: 2020/11/09 16:14:45 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		error_case(char **s_buf, char **line, int *ret)
{
	save_free(s_buf);
	if (*ret == -1)
		save_free(line);
}

static char		*save_buf(char **s_buf, char **line, int *ret)
{
	char		*n;

	*ret = 1;
	n = NULL;
	if (*s_buf)
	{
		if ((n = ft_strchr(*s_buf, '\n')))
			*n++ = '\0';
		*line = ft_strdup_gnl(*s_buf, ret);
		(n) ? ft_strcpy(*s_buf, n) : save_free(s_buf);
	}
	else
		*line = ft_strdup_gnl("\0", ret);
	return (n);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*s_buf = NULL;
	char		*n;
	char		*tmp;
	int			ret;

	ret = (fd < 0 || BUFFER_SIZE < 1 || !line) ? -1 : 0;
	n = (!ret) ? save_buf(&s_buf, line, &ret) : NULL;
	while (!n && ret != -1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			n++;
			save_free(&s_buf);
			s_buf = ft_strdup_gnl(n, &ret);
		}
		tmp = *line;
		*line = ft_strjoin_gnl(*line, buf, &ret);
		save_free(&tmp);
	}
	if (ret == 0 || ret == -1)
		error_case(&s_buf, line, &ret);
	return ((ret >= 1) ? 1 : ret);
}
