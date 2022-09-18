/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:40:59 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/05 16:45:24 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc_gnl(int count, int size)
{
	void	*p;
	char	*str;
	int		i;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	str = (char *)p;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s2 == NULL)
		return (NULL);
	str = ft_calloc_gnl(sizeof(char), (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (str);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int				i;
	unsigned char	c_rep;

	i = 0;
	c_rep = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c_rep)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c_rep)
		return ((char *)&s[i]);
	return (NULL);
}


char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*sub;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = ft_strlen_gnl(s);
	if (len > i)
		len = i;
	if (!len)
		return (NULL);
	sub = ft_calloc_gnl(sizeof(char), len + 1);
	if (!sub)
		return (NULL);
	j = 0;
	while (start < i && j < len)
	{
		sub[j] = s[start];
		j++;
		start++;
	}
	return (sub);
}
