/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:52:18 by mrubio            #+#    #+#             */
/*   Updated: 2020/08/28 20:09:43 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		total;
	int		x;
	int		z;

	z = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
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

char			*ft_strdup(const char *src)
{
	char	*s;
	int		x;

	x = ft_strlen(src) + 1;
	if ((s = malloc(x)) == NULL)
		return (NULL);
	if (src == NULL)
	{
		free(s);
		return (NULL);
	}
	ft_memcpy(s, src, x);
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

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	int x;
	int z;

	x = 0;
	z = 0;
	while ((dest[x]) && (x < (int)size))
		x++;
	while ((src[z]) && (x + z + 1) < (int)size)
	{
		dest[x + z] = src[z];
		z++;
	}
	if (x < (int)size)
		dest[x + z] = '\0';
	return (x + ft_strlen(src));
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int x;

	x = 0;
	if (!dest || !src)
		return (0);
	if (size != 0)
	{
		while ((src[x] != '\0') && (x < size - 1))
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	while (src[x] != '\0')
		x++;
	return (x);
}

