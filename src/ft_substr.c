/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:56:17 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/18 11:35:34 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (len > i)
		len = i;
	sub = ft_calloc(sizeof(char), len + 1);
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
