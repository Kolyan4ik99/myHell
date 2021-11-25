/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 05:41:43 by cclock            #+#    #+#             */
/*   Updated: 2021/11/20 14:37:12 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	open_one_redirect(int *fd, char *filename)
{
	if (fd[1] >= 0)
		close(fd[1]);
	fd[1] = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd[1] < 1)
		return (ft_return(strerror(errno), -1));
	return (0);
}

int	open_double_redirect(int *fd, char *filename)
{
	if (fd[1] >= 0)
		close(fd[1]);
	fd[1] = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0774);
	if (fd[1] < 1)
		return (ft_return(strerror(errno), -1));
	return (0);
}

int	open_rev_redirect(int *fd, char *filename)
{
	if (fd[0] >= 0)
		close(fd[0]);
	fd[0] = open(filename, O_RDONLY);
	if (fd[0] < 1)
		return (ft_return(strerror(errno), -1));
	return (0);
}

void	write_to_fd(int *fd, char *name)
{
	char	*str;

	str = "";
	while (ft_strcmp(str, name))
	{
		str = readline(">");
		if (!str)
			return ;
		if (!ft_strcmp(str, name))
		{
			free(str);
			return ;
		}
		write(fd[0], str, ft_strlen(str));
		write(fd[0], "\n", 1);
		free(str);
	}
}

int	open_double_rev_redirect(int *fd, char *filename)
{
	if (fd[0] >= 0)
		close(fd[0]);
	fd[0] = open(".double-back.txt", O_WRONLY | O_CREAT | O_TRUNC, 0774);
	if (fd[0] < 1)
		return (ft_return(strerror(errno), -1));
	write_to_fd(fd, filename);
	close(fd[0]);
	fd[0] = open(".double-back.txt", O_RDONLY);
	if (fd[0] < 1)
		return (ft_return(strerror(errno), -1));
	return (0);
}
