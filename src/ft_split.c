/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:10:04 by tel-dana          #+#    #+#             */
/*   Updated: 2022/05/15 15:14:28 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c, int counter)
{
	int	len;

	len = 0;
	while (s[counter] != c && s[counter] != '\0')
	{
		len++;
		counter++;
	}
	return (len);
}

static char	*trim_word(const char *s, char c, int counter)
{
	char	*trimmed;
	int		i;

	trimmed = ft_calloc(sizeof(char), word_len(s, c, counter) + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (s[counter])
	{
		if (s[counter] != c)
		{
			trimmed[i] = s[counter];
			if (s[counter + 1] == c || s[counter + 1] == '\0')
				break ;
			else
			{
				counter++;
				i++;
			}
		}
		else
			counter++;
	}
	return (trimmed);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		flag;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	split = ft_calloc(sizeof(char *), num_of_words(s, c) + 1);
	if (!split)
		return (NULL);
	j = 0;
	k = 0;
	flag = -1;
	while (j <= (int)ft_strlen(s))
	{
		if (s[j] != c && flag < 0)
			flag = j;
		else if ((s[j] == c || j == (int)ft_strlen(s)) && flag >= 0)
		{
			split[k++] = trim_word(s, c, flag);
			flag = -1;
		}
		j++;
	}
	return (split);
}
