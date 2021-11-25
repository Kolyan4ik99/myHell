/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:17:30 by cclock            #+#    #+#             */
/*   Updated: 2021/11/21 22:13:31 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_check_map_char(char *map)
{
	if ((map[0] == '|' && ft_strchr(SYMB, map[1]) != NULL)
		|| (map[0] == '<' && map[1]
			!= '<' && ft_strchr(SYMB, map[1]) != NULL)
		|| (map[0] == '>' && map[1]
			!= '>' && ft_strchr(SYMB, map[1]) != NULL))
		return (1);
	else
		return (0);
}

void	ft_make_choice(char **cmd, t_list_env **envs_lsts, t_one_cmd_t **all)
{
	if (ft_strcmp(*cmd, "exit"))
		all = ft_do(cmd, *envs_lsts, 0);
	else
		ft_exit("By by O_o\n", 0);
	if (all)
	{
		execute_program(all, envs_lsts);
		free_all(all);
	}
}

int	main_circle(t_list_env **envs_lsts)
{
	char		*cmd;
	t_one_cmd_t	**all;
	char		*start_dir;

	cmd = "";
	all = NULL;
	start_dir = fill_dir(*envs_lsts);
	if (!start_dir)
		ft_exit("Bad malloc : расходимся\n", -1);
	while (!ft_strnstr(cmd, "exit", 4))
	{
		cmd = readline("sons_of_mother's_friends$ ");
		if (!cmd)
			return (ft_return("By by O_o\n", 1));
		add_to_history(cmd, start_dir);
		ft_make_choice(&cmd, envs_lsts, all);
		if (cmd)
			free(cmd);
	}
	return (0);
}

int	add_vopr(t_list_env *list)
{
	t_list_env	*iter;
	char		*vopr;
	char		*ed;

	iter = list;
	while (iter->next)
		iter = iter->next;
	vopr = ft_strdup("?");
	ed = ft_strdup("0");
	if (!vopr || !ed)
		ft_exit("Bad start minishell\n", -1);
	iter->next = ft_lstnew_env(vopr, ed);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_list_env	*envs_lsts;

	if (argc != 1 || argv[0][0] == ' ')
		return (1);
	envs_lsts = ft_envs_lists(env, 0, 0);
	add_vopr(envs_lsts);
	signal_catch();
	return (main_circle(&envs_lsts));
}
