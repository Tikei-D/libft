/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:09:57 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/18 11:33:52 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = ft_calloc(sizeof(t_list), 1);
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = (NULL);
	return (new_node);
}
