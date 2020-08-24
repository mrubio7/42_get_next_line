/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:05:05 by mrubio            #+#    #+#             */
/*   Updated: 2020/08/24 22:07:26 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*str[256];
	char			*newstr;
	int				x;
	int				r;

	if (fd < 1 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(newstr = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (str[fd])
		ft_bzero(str[fd], ft_strlen(str[fd]));
	while ((r = read(fd, newstr, BUFFER_SIZE)) > 0)
	{
		str[fd] = ft_strjoin(str[fd], newstr);
		free(newstr);
		newstr = malloc(BUFFER_SIZE + 1);
		if ((x = ft_strchr_num(str[fd], '\n')) > -1)
		{
			line[fd-3] = ft_strldup(str[fd], x);
			ft_freeall(newstr, str[fd]);
			r = 0;
			return (1);
		}
	}
	if (r == 0)
		line[fd-3] = ft_strldup(str[fd], ft_strlen(str[fd]));
		ft_freeall(newstr, str[fd]);
		return (0);
	return (-1);
}

int		main(void)
{
	int fd;
	char **lines;
	int a;

	lines = malloc(999);
	fd = open("/Users/macbookpro/Desktop/42/get_next_line/prueba.txt", O_RDONLY);
	while ((a = get_next_line(fd, lines)) >= 0)
	{
		printf("%s\n", lines[fd-3]);
	}
}
