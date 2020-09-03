/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:05:05 by mrubio            #+#    #+#             */
/*   Updated: 2020/09/03 10:08:24 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static int		find_n(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '\n')
			return (x);
		x++;
	}
	return (-1);
}

static void		ft_freemem(char *mem)
{
	if (*mem)
		free(mem);
}

static int		ft_movestr(char **str, int x, char **line)
{
	char	*temp;

	(* str)[x] = '\0';
	*line = ft_strdup(*str);
	temp = ft_strdup(*str + x + 1);
	ft_freemem(*str);
	*str = temp;
	return (1);
}

static int		find_EOF(char **str, char **line)
{
	int		stp;

	if (*str && (stp = find_n(*str)) > 0)
		return (ft_movestr(str, stp, line));
	if (*str)
	{
		*line = *str;
		*str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*str[256];
	char			*newstr;
	int				x;
	int				r;

	if (fd < 3 || fd > 256 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(newstr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((r = read(fd, newstr, BUFFER_SIZE)) > 0)
	{
		if (!str[fd])
			str[fd] = ft_strdup("");
		newstr[r] = '\0';
		str[fd] = ft_strjoin(str[fd], newstr);
		if ((x = find_n(str[fd])) > -1)
		{
			ft_freemem(newstr);
			return(ft_movestr(&str[fd], x, line));
		}
	}
	ft_freemem(newstr);
	if (r == 0 && str[fd])
		return (find_EOF(&str[fd], line));
	return (-1);
}

int		main(void)
{
	int fd;
	char **lines;
	int a;

	lines = malloc(999);
	fd = open("/Users/mrubio/Desktop/42/42_get_next_line/prueba.txt", O_RDONLY);
	while ((a = get_next_line(fd, lines)) > -1)
	{
		printf("%s\n", lines[fd-3]);
	}
}