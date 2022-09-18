/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:19:32 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/18 11:34:10 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	char			*tdst;
	const char		*tsrc;

	tdst = (char *)dst;
	tsrc = (const char *)src;
	if (!src && !dst)
		return (NULL);
	i = 0;
	if (tdst > tsrc)
	{
		while (len-- > 0)
			tdst[len] = tsrc[len];
	}
	else
	{
		while (i < len)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	}
	return (dst);
}
