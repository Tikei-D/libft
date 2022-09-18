/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:07:47 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/18 11:35:23 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	int				j;
	char			*h;
	char			*ndl;

	i = 0;
	h = (char *)haystack;
	ndl = (char *)needle;
	if (ndl[0] == '\0')
		return (h);
	while (h[i] != '\0' && i < n)
	{
		if (h[i] == ndl[0])
		{
			j = 1;
			while (h[i + j] == ndl[j] && ndl[j] != '\0' && i + j < n)
			{
				j++;
			}
			if (ndl[j] == '\0')
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
