/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:05:05 by mrubio            #+#    #+#             */
/*   Updated: 2020/08/20 18:35:33 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*str[256];
	char			*new;
	int				x;

	if (fd < 1 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(new = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (read(fd, new, BUFFER_SIZE) > 0)
	{
		new[BUFFER_SIZE + 1] = '\0';
		str[fd] = ft_strjoin(str[fd], new);
		free(new);
		new = malloc(BUFFER_SIZE + 1);
		x = ft_strchr_num(str[fd], '\n');
		if (x > -1)
		{
			line[fd-3] = ft_strldup(str[fd], x);
			free(str[fd]);
			return (1);
		}
	}
	return (-1);
}

int		main(void)
{
	int fd;
	char **lines;

	lines = malloc(999);
	fd = open("/Users/macbookpro/Desktop/42/get_next_line/prueba.txt", O_RDONLY);
	get_next_line(fd, lines);
	printf("%s", lines[0]);
}