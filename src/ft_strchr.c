/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:47:22 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/18 11:34:45 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c_rep;

	i = 0;
	c_rep = (unsigned char)c;
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
