/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:48:08 by grfck             #+#    #+#             */
/*   Updated: 2021/11/21 22:05:48 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_list_env	*find_list(t_list_env *list, char *key)
{
	t_list_env	*iter;

	iter = list;
	while (iter)
	{
		if (ft_strcmp(iter->key, key) == 0)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

void	ft_add_new_env(char *str, t_list_env *list)
{
	char		*key;
	char		*value;
	char		*old_value;
	t_list_env	*wanted;

	if (ft_parse_new_env(str, &key, &value) == 0)
		return ;
	wanted = find_list(list, key);
	if (wanted == NULL)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = ft_lstnew_env(key, value);
		if (list->next == NULL)
			ft_exit("Error malloc", 1);
	}
	else
	{
		old_value = wanted->value;
		wanted->value = value;
		if (old_value)
			free(old_value);
		if (wanted->key != key && key)
			free(key);
	}
}

int	call_export(t_one_cmd_t *all, t_list_env *list)
{
	int	i;

	i = 1;
	if (all->arg[1] == NULL)
		ft_sort_print_envs(list, 0);
	while (all->arg[i] != NULL)
		ft_add_new_env(all->arg[i++], list);
	return (0);
}

int	change_list(t_list_env *list, char *value, char *key)
{
	t_list_env	*need_list;

	(void)value;
	need_list = find_list(list, key);
	if (!need_list)
		return (-1);
	if (need_list->value)
		free(need_list->value);
	need_list->value = getcwd(NULL, 0);
	if (!need_list->value)
		ft_exit("Bad malloc\n", -1);
	return (0);
}
