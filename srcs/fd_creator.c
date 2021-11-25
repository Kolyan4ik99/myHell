/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_creator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <cclock@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:39:50 by cclock            #+#    #+#             */
/*   Updated: 2021/11/20 14:03:27 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	find_fdin(t_fd *f_fd, t_one_cmd_t *ar)
{
	int	fd;

	fd = 0;
	if (ar->fd[0] >= 0)
		fd = ar->fd[0];
	else if (f_fd->pipe_fd[0])
		fd = dup(f_fd->pipe_fd[0]);
	else
		fd = dup(f_fd->orig_fd[0]);
	if (f_fd->pipe_fd[0])
		close(f_fd->pipe_fd[0]);
	f_fd->pipe_fd[0] = 0;
	return (fd);
}

int	find_fdout(t_fd *f_fd, t_one_cmd_t *ar)
{
	int	fd;
	int	ret;

	fd = 0;
	if (ar->flag == 5)
	{
		ret = pipe(f_fd->pipe_fd);
		if (ret == -1)
			ft_exit("Bad pipe", -1);
		fd = dup(f_fd->pipe_fd[1]);
	}
	if (ar->fd[1] >= 0)
	{
		if (fd)
			close(fd);
		fd = ar->fd[1];
	}
	else if (ar->flag != 5)
		fd = dup(f_fd->orig_fd[1]);
	if (f_fd->pipe_fd[1])
		close(f_fd->pipe_fd[1]);
	f_fd->pipe_fd[1] = 0;
	return (fd);
}

void	close_all_fd(t_one_cmd_t **all, t_fd *fd)
{
	int	i;

	i = -1;
	while (all[++i])
	{
		if (all[i]->fd[0] >= 0)
			close(all[i]->fd[0]);
		if (all[i]->fd[1] >= 0)
			close(all[i]->fd[1]);
	}
	if (fd->orig_fd[0] >= 0)
		close(fd->orig_fd[0]);
	if (fd->orig_fd[1] >= 0)
		close(fd->orig_fd[1]);
}

int	fill_fd(t_one_cmd_t **all)
{
	int	i;

	i = -1;
	while (all[++i])
	{
		all[i]->fd[0] = -1;
		all[i]->fd[1] = -1;
		if (all[i + 1] && all[i + 1]->cmd)
		{
			if (all[i]->flag == 1)
				open_one_redirect(all[i]->fd, all[i + 1]->cmd);
			else if (all[i]->flag == 2)
				open_rev_redirect(all[i]->fd, all[i + 1]->cmd);
			else if (all[i]->flag == 3)
				open_double_redirect(all[i]->fd, all[i + 1]->cmd);
			else if (all[i]->flag == 4)
				open_double_rev_redirect(all[i]->fd, all[i + 1]->cmd);
		}
	}
	return (0);
}
