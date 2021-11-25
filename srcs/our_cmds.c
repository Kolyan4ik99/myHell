/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:31:31 by cclock            #+#    #+#             */
/*   Updated: 2021/11/20 13:59:29 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	call_cd(t_one_cmd_t *all, t_list_env *list)
{
	int		ret;
	char	*dir;

	dir = getenv("HOME");
	if (all->arg[1] == NULL)
	{
		ret = chdir(dir);
		if (ret)
		{
			printf("Не мочь поменять директорию на : \"%s\"\n", all->arg[1]);
			return (-1);
		}
	}
	else if ((all->arg[1] && !all->arg[2]))
	{
		dir = all->arg[1];
		ret = chdir(dir);
		if (ret)
		{
			printf("Не мочь поменять директорию на : \"%s\"\n", all->arg[1]);
			return (-1);
		}
	}
	change_list(list, dir, "PWD");
	return (0);
}

int	call_echo(t_one_cmd_t *all, int fl, int i)
{
	if (all->arg[1] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (ft_strcmp(all->arg[i], "-n") == 0)
		++i;
	if (i > 1)
		fl = 1;
	while (all->arg[i] != NULL)
	{
		ft_putstr_fd(all->arg[i], 1);
		if (all->arg[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		++i;
	}
	if (fl == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	call_env(t_list_env *list)
{
	t_list_env	*iter;

	iter = list;
	while (iter)
	{
		if (ft_strcmp(iter->key, "?"))
			printf("%s=%s\n", iter->key, iter->value);
		iter = iter->next;
	}
	return (0);
}

int	call_pwd(t_list_env *list)
{
	printf("%s\n", ft_find_env("PWD", list));
	return (0);
}
