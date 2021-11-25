/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:39:50 by cclock            #+#    #+#             */
/*   Updated: 2021/11/21 22:12:14 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	find_and_use_command(t_one_cmd_t *all, t_list_env **list, int mode)
{
	int	ret;

	ret = 0;
	if (mode == 1)
		ret = find_our_cmd(all, *list);
	else
	{
		if (!ft_strcmp(all->cmd, "cd"))
		{
			call_cd(all, *list);
			return (1);
		}
		if (!ft_strcmp(all->cmd, "export"))
		{
			(call_export(all, *list));
			return (1);
		}
		if (!ft_strcmp(all->cmd, "unset"))
		{
			(ft_unset(all, list, 1));
			return (1);
		}
	}
	return (ret);
}

int	catch_bad_cmnd(t_one_cmd_t *all)
{
	if (errno == ENOENT)
	{
		printf("Damn: command not found: %s\n", all->cmd);
		return (-1);
	}
	if (errno == EACCES)
	{
		printf("Damn: permission denied: %s\n", all->cmd);
		return (-1);
	}
	return (0);
}

void	close_fd(int *fd)
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
}

void	free_all(t_one_cmd_t **all)
{
	int	i;
	int	j;

	i = -1;
	while (all[++i] != NULL)
	{
		j = 0;
		ft_free(all[i]->cmd);
		if (all[i]->arg)
		{
			while (all[i]->arg[++j])
			{
				if (all[i]->arg[j])
					ft_free(all[i]->arg[j]);
			}
			if (all[i]->arg)
				free(all[i]->arg);
		}
		if (all[i])
			free(all[i]);
	}
	if (all)
		free(all);
}

int	execute_program(t_one_cmd_t **all, t_list_env **list)
{
	int		i;
	t_fd	f_fd;

	i = -1;
	create_fd(&f_fd);
	fill_fd(all);
	while (all[++i])
	{
		if (i > 0 && all[i - 1]->flag > 0 && all[i - 1]->flag < 5)
			continue ;
		if (find_and_use_command(all[i], list, 0))
			continue ;
		if (errno == ENOENT)
			return (ft_return("\n", 0));
		execute_command(all[i], *list, &f_fd);
		close_fd(all[i]->fd);
	}
	fill_vopr(*list);
	close_all_fd(all, &f_fd);
	return (0);
}
