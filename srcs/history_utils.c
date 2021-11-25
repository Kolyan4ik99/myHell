/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 06:28:44 by cclock            #+#    #+#             */
/*   Updated: 2021/11/18 17:18:45 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*fill_dir(t_list_env *envs_lsts)
{
	char	*ptr;
	char	*tmp;
	char	*dir;

	dir = ft_find_env("PWD", envs_lsts);
	tmp = ft_strdup("/history.txt");
	ptr = ft_strjoin(dir, tmp);
	if (!ptr)
		ft_exit("Malloc bad work\n", -1);
	if (tmp)
		free(tmp);
	return (ptr);
}

static int	valid_cmd(char *cmd)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (cmd[++i])
	{
		if (ft_isprint(cmd[i]))
			++count;
		if (count > 0)
			return (0);
	}
	return (1);
}

int	add_to_history(char *text, char *dir)
{
	int		fd;

	if (valid_cmd(text))
		return (0);
	add_history(text);
	fd = open(dir, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd < 0)
		return (ft_return(strerror(errno), errno));
	write(fd, "\t\t", 2);
	write(fd, text, ft_strlen(text));
	write(fd, "\n", 1);
	close(fd);
	return (0);
}
