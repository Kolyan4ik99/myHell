/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_args_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 03:45:09 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/20 14:36:56 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_mix_count(t_one_cmd_t **cmds, t_mix_args *x, int i)
{
	if (x->start == -1 && cmds[i]->flag != 5 && cmds[i]->flag != 0)
	{
		x->start = i;
		x->count++;
		if (ft_strncmp(cmds[i]->cmd, "", 1) == 0)
			x->fl = 1;
		x->count_args = x->count_args + ft_count_args(cmds[i]);
	}
	if (i != 0 && x->start >= 0 && cmds[i - 1]->flag != 5
		&& cmds[i - 1]->flag != 0)
	{
		x->count++;
		x->count_args = x->count_args + ft_count_args(cmds[i]);
		if (cmds[i]->flag == 5 || cmds[i]->flag == 0)
			x->end = i;
	}
}

void	ft_mix(t_one_cmd_t **cmds)
{
	int			i;
	t_mix_args	x;

	i = 0;
	ft_null_mix_args(&x);
	while (cmds[i] != NULL)
	{
		ft_mix_count(cmds, &x, i);
		if (x.count != 0 && (cmds[i]->flag == 5 || cmds[i]->flag == 0))
		{
			ft_change_args(cmds, x);
			ft_null_mix_args(&x);
		}
		i++;
	}
}

void	ft_null_mix_args(t_mix_args *x)
{
	x->start = -1;
	x->count = 0;
	x->count_args = 0;
	x->end = -1;
	x->fl = 0;
}

int	ft_count_args(t_one_cmd_t *cmds)
{
	int	c;

	c = 0;
	while (cmds->arg[c] != NULL)
		c++;
	return (c - 1);
}

void	ft_fill_null_temp(int j, char **temp_args,
			t_one_cmd_t **cmds, t_mix_args *x)
{
	if (j == 0 && x->fl == 1)
	{
		temp_args[0] = cmds[j]->arg[1];
		cmds[x->start]->cmd = cmds[j]->arg[1];
	}
}
