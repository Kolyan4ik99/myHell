/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:47:20 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 16:59:22 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*temp;

	temp = *list;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}
