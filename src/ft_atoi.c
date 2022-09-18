/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:06:38 by tel-dana          #+#    #+#             */
/*   Updated: 2022/04/23 15:16:43 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char ch)
{
	if (ch >= 9 & ch <= 13 || ch == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*s;
	long	i;
	long	result;
	int		sign;

	s = (char *)str;
	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(s[i]))
		i++;
	if (s[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		result = (result * 10) + s[i] - 48;
		i++;
	}
	return (result * sign);
}
