/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:12:34 by tel-dana          #+#    #+#             */
/*   Updated: 2022/06/08 17:23:54 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j])
		j++;
	while (is_set(s1[i], set))
		i++;
	while (is_set(s1[j - 1], set) && i < j)
		j--;
	new_str = ft_calloc(sizeof(char), j - i + 1);
	if (!new_str)
		return (NULL);
	while (i < j)
		new_str[k++] = s1[i++];
	return (new_str);
}
