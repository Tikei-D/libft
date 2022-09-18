/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:39:14 by tel-dana          #+#    #+#             */
/*   Updated: 2022/09/18 11:33:56 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}
