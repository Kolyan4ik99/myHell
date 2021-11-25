/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:39:50 by cclock            #+#    #+#             */
/*   Updated: 2021/11/21 21:27:51 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	exec_child(t_one_cmd_t *all, t_list_env *list, t_fd *f_fd)
{
	int	ret;

	ret = find_and_use_command(all, &list, 1);
	if (!ret)
		exit(g_signal_code);
	fill_full_cmd(all, list);
	ret = execve(all->cmd, all->arg, NULL);
	dup2(f_fd->orig_fd[0], 0);
	close(f_fd->orig_fd[0]);
	dup2(f_fd->orig_fd[1], 1);
	close(f_fd->orig_fd[1]);
	catch_bad_cmnd(all);
	exit(ret);
}

int	exec_batya(t_fd *f_fd)
{
	dup2(f_fd->orig_fd[0], 0);
	dup2(f_fd->orig_fd[1], 1);
	return (0);
}

int	execute_command(t_one_cmd_t *all, t_list_env *list, t_fd *f_fd)
{
	int	pid;

	fiff_fd(all, f_fd);
	pid = fork();
	if (pid < 0)
		ft_exit("Bad fork create", -1);
	if (pid == 0)
		exec_child(all, list, f_fd);
	else
	{
		wait(&g_signal_code);
		if (g_signal_code > 0
			&& !(g_signal_code >= 130 && g_signal_code <= 131))
			g_signal_code = 127;
		exec_batya(f_fd);
	}
	return (0);
}
