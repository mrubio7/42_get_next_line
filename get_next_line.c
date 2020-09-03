/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:05:05 by mrubio            #+#    #+#             */
/*   Updated: 2020/09/03 13:21:57 by mrubio           ###   ########.fr       */
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

	(*str)[x] = '\0';
	*line = ft_strdup(*str);
	if (ft_strlen(*str + x + 1) > 0)
	{
		temp = ft_strdup(*str + x + 1);
		ft_freemem(*str);
		*str = temp;
	}
	else
		ft_freemem(*str);
	return (1);
}

static int		find_EOF(char **str, char **line)
{
	int		find;
	
	if (*str && (find = find_n(*str)) > -1)
		return(ft_movestr(str, find, line));
	if (*str)
	{
		*line = *str;
		ft_freemem(*str);
		*str = NULL;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*str[256];
	char			*newstr;
	char			*temp;
	int				x;
	int				r;

	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(newstr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((r = read(fd, newstr, BUFFER_SIZE)) > 0)
	{
		newstr[r] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(newstr);
		else
		{
			temp = ft_strjoin(str[fd], newstr);
			ft_freemem(str[fd]);
			str[fd] = temp;
		}
		if ((x = find_n(str[fd])) > -1)
		{
			ft_freemem(newstr);
			return(ft_movestr(&str[fd], x, line));
		}
	}
	if (r == 0 && str[fd])
		return (find_EOF(&str[fd], line));
	else if (r < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}

int		main(void)
{
	int fd;
	char **lines;
	int a;

	lines = malloc(999);
	fd = open("/Users/mrubio/Desktop/42/42_get_next_line/prueba.txt", O_RDONLY);
	while ((a = get_next_line(fd, lines)) > 0)
	{
		printf("%s\n", lines[fd-3]);
		printf("...................\n");
	}
	free(lines);
}
