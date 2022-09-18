/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:06:05 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/05 16:45:15 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Calls the function Read multiple times and, at each call, stores what is contained in the buffer into the stash using strjoin.  
char	*read_and_stash(int fd, char *stash, char *buffer)
{
	int	count;

	count = BUFFER_SIZE;
	while (count > 0 && !ft_strchr_gnl(stash, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (count == 0)
			break ;
		buffer[count] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

// Extracts the line that ends with \n from the stash using substr. 
char	*extract_line(char *stash)
{
	char	*line;
	char	*index;

	index = ft_strchr_gnl(stash, '\n');
	if (index == NULL)
		return (ft_substr_gnl(stash, 0, 1000000000));
	line = ft_substr_gnl(stash, 0, (index - stash + 1));
	return (line);
}

// Extracts the remaining bytes from the stash using substr and stores it into Cleaned stash. 
char	*clean_stash(char *stash)
{
	char	*index;
	char	*cleaned_stash;
	int		len;

	cleaned_stash = NULL;
	index = ft_strchr_gnl(stash, '\n');
	len = ft_strlen_gnl(stash);
	if (index)
		cleaned_stash = ft_substr_gnl(index + 1, 0, len);
	if (stash)
		free(stash);
	return (cleaned_stash);
}

// Reads and stashes what was read into the static variable stash
// then stores the extracted line (that ends with \n) into the variable line
// then after a clean up, stores the remaining bytes back into the stash for the next call. 
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_and_stash(fd, stash, buffer);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
