/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:24:48 by cclock            #+#    #+#             */
/*   Updated: 2021/11/18 21:42:55 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	find_our_cmd(t_one_cmd_t *all, t_list_env *list)
{
	if (!ft_strcmp(all->cmd, "echo"))
		return (call_echo(all, 0, 1));
	else if (!ft_strcmp(all->cmd, "pwd"))
		return (call_pwd(list));
	else if (!ft_strcmp(all->cmd, "export"))
		return (call_export(all, list));
	else if (!ft_strcmp(all->cmd, "env"))
		return (call_env(list));
	else if (all->cmd[0] == '\0')
		return (0);
	else
		return (1);
}

int	find_linux_cmd(t_one_cmd_t *all, char *str)
{
	int		fd;
	char	*tmp;
	char	*tmp_r;

	tmp_r = ft_strjoin(str, "/");
	if (!tmp_r)
		ft_exit("Malloc сломался\n", -1);
	tmp = ft_strjoin(tmp_r, all->cmd);
	if (!tmp)
		ft_exit("Malloc сломался\n", -1);
	ft_free(str);
	fd = open(tmp, O_RDONLY);
	if (fd >= 0)
	{
		tmp_r = all->cmd;
		all->cmd = tmp;
		ft_free(tmp_r);
		close(fd);
		return (0);
	}
	close(fd);
	free(tmp_r);
	free(tmp);
	errno = -2;
	return (-2);
}

int	fill_full_cmd(t_one_cmd_t *all, t_list_env *list)
{
	int		i;
	char	**str;
	int		ret;

	ret = -1;
	i = -1;
	str = ft_split(ft_find_env("PATH", list), ':');
	if (!str)
		ft_exit("Malloc сломался\n", -1);
	while (str[++i])
	{
		ret = find_linux_cmd(all, str[i]);
		if (!ret)
		{
			errno = ENOENT;
			break ;
		}
	}
	free(str);
	return (ret);
}

void	ft_free(char *str)
{
	if (str)
		free(str);
}
