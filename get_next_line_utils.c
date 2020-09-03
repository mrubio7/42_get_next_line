/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:52:18 by mrubio            #+#    #+#             */
/*   Updated: 2020/09/03 13:06:08 by mrubio           ###   ########.fr       */
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
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return(ft_strdup(s2));
	else if (!s2)
		return(ft_strdup(s1));
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

	if (src == NULL)
		return (NULL);
	x = ft_strlen(src);
	if ((s = malloc(x + 1)) == NULL)
		return (NULL);
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
