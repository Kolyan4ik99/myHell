/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:56:16 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/18 19:45:42 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_list_env	*ft_lstnew_env(char *key, char *value)
{
	t_list_env	*lstnew;

	lstnew = (t_list_env *)malloc(sizeof(t_list_env));
	if (lstnew == NULL)
		return (NULL);
	lstnew->key = key;
	lstnew->value = value;
	lstnew->i = 0;
	lstnew->next = NULL;
	return (lstnew);
}
