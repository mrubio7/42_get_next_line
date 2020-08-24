/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:52:18 by mrubio            #+#    #+#             */
/*   Updated: 2020/08/24 19:17:48 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		total;
	int		x;
	int		z;

	z = 0;
	x = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	total = ft_strlen(s1) + ft_strlen(s2);
	if ((res = (char *)malloc(total + 1)) == NULL)
		return (NULL);
	while (s1[x] != '\0')
	{
		res[x] = s1[x];
		x++;
	}
	while (s2[z] != '\0')
	{
		res[x + z] = s2[z];
		z++;
	}
	res[x + z] = '\0';
	return (res);
}

int				ft_strchr_num(char *s, int c)
{
	int x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			return (x);
		x++;
	}
	return (-1);
}

char			*ft_strldup(const char *src, int x)
{
	char	*s;

	if ((s = malloc(x + 1)) == NULL)
		return (NULL);
	if (src == NULL)
	{
		free(s);
		return (NULL);
	}
	ft_memcpy(s, src, x);
	s[x] = '\0';
	return (s);
}

size_t			ft_strlen(const char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

void			*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char		*s;
	char		*d;

	
	if (!dest && !src)
		return (NULL);
	s = (char *)src;
	d = dest;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

void			ft_bzero(void *s, unsigned int n)
{
	char *f;

	f = s;
	while (n)
	{
		*f = 0;
		f++;
		n--;
	}
}

void			ft_freeall(char *a, char *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
}

