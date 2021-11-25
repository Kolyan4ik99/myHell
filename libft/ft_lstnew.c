/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:46:16 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 16:23:54 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
