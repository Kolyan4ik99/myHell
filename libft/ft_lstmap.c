/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:28:43 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/13 04:36:42 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		len_lst;
	t_list	*new_lst;
	t_list	*add_lst;

	if (!lst)
		return (NULL);
	len_lst = ft_lstsize(lst);
	new_lst = NULL;
	while (len_lst > 0)
	{
		add_lst = ft_lstnew(f(lst->content));
		if (add_lst == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, add_lst);
		len_lst--;
	}
	return (new_lst);
}
