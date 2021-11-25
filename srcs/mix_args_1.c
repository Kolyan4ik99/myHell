/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_args_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 03:45:09 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/21 12:59:46 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_change_args_fill_temp(int j, char **temp_args,
			t_one_cmd_t **cmds, t_mix_args *x)
{
	int	a;
	int	i;

	i = 1;
	while (j <= x->end)
	{
		a = 1;
		if (ft_count_args(cmds[j]) == 0)
			j++;
		else
		{
			ft_fill_null_temp(j, temp_args, cmds, x);
			while (cmds[j]->arg[a + x->fl] != NULL)
			{
				temp_args[i] = cmds[j]->arg[a + x->fl];
				cmds[j]->arg[a + x->fl] = NULL;
				a++;
				i++;
			}
			if (j == 0)
				x->fl = 0;
			j++;
		}
	}
}

void	ft_free_start_args(t_one_cmd_t **cmds, t_mix_args x)
{
	int	i;

	i = 1;
	while (cmds[x.start]->arg[i] != NULL)
	{
		if (cmds[x.start]->arg[i] != NULL)
			free(cmds[x.start]->arg[i++]);
	}
	free(cmds[x.start]->arg);
}

void	ft_change_args(t_one_cmd_t **cmds, t_mix_args x)
{
	char	**temp_args;

	temp_args = (char **)ft_calloc(x.count_args + 2, sizeof(char *));
	if (temp_args == NULL)
		ft_exit("Error malloc", 1);
	temp_args[0] = cmds[x.start]->arg[0];
	temp_args[x.count_args + 1] = NULL;
	ft_change_args_fill_temp(x.start, temp_args, cmds, &x);
	ft_free_start_args(cmds, x);
	cmds[x.start]->arg = temp_args;
}
