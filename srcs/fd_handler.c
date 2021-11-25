/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <cclock@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:39:50 by cclock            #+#    #+#             */
/*   Updated: 2021/11/20 14:03:27 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	create_fd(t_fd *fd)
{
	fd->orig_fd[0] = dup(0);
	fd->orig_fd[1] = dup(1);
	fd->pipe_fd[0] = -1;
	fd->pipe_fd[1] = -1;
}

void	fiff_fd(t_one_cmd_t *all, t_fd *f_fd)
{
	all->fd[0] = find_fdin(f_fd, all);
	all->fd[1] = find_fdout(f_fd, all);
	dup2(all->fd[0], 0);
	close(all->fd[0]);
	dup2(all->fd[1], 1);
	close(all->fd[1]);
}

void	fill_vopr(t_list_env *list)
{
	t_list_env	*iter;
	char		*tmp;

	iter = list;
	tmp = ft_itoa(g_signal_code);
	if (!tmp)
		ft_exit("Bad malloc\n", -1);
	while (iter)
	{
		if (!ft_strcmp(iter->key, "?"))
		{
			free(iter->value);
			iter->value = tmp;
			return ;
		}
		iter = iter->next;
	}
}
