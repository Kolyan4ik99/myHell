/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:54:25 by grfck             #+#    #+#             */
/*   Updated: 2021/11/21 22:31:09 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_strcmp(char *str, char *ptr)
{
	int	i;

	i = 0;
	while (str[i] || ptr[i])
	{
		if (!str[i])
			return (ptr[i]);
		if (!ptr[i])
			return (str[i]);
		if (str[i] - ptr[i] != 0)
			return (str[i] - ptr[i]);
		++i;
	}
	return (0);
}

t_list_env	*ft_del_one_env(t_list_env *lst)
{
	t_list_env	*tmp;

	tmp = lst->next;
	if (lst->key)
		free(lst->key);
	if (lst->value)
		free(lst->value);
	if (lst)
		free(lst);
	return (tmp);
}

t_list_env	*ft_find_del_env(t_list_env *lst, char *key)
{
	t_list_env	*temp;
	t_list_env	*temp_start;

	if (ft_strcmp(key, lst->key) == 0)
	{
		temp = ft_del_one_env(lst);
		return (temp);
	}
	temp_start = lst;
	while (lst != NULL)
	{
		temp = lst->next;
		if (temp != NULL && ft_strcmp(key, temp->key) == 0)
			lst->next = ft_del_one_env(temp);
		lst = lst->next;
	}
	return (temp_start);
}

int	ft_unset(t_one_cmd_t *all, t_list_env **list, int i)
{
	while (all->arg[i] != NULL)
	{
		if (ft_check_new_env(all->arg[i], 0))
			printf("unset: `%s': not a valid identifier\n", all->arg[i]);
		else
			*list = ft_find_del_env(*list, all->arg[i]);
		i++;
	}
	return (0);
}
