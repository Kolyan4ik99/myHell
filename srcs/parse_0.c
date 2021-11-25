/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:01:18 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/20 13:56:55 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	**ft_input_args(char *map, char *str, int count, int fl)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	j = 0;
	args = (char **)ft_calloc(count + 2, sizeof(char *));
	args[0] = ft_strdup("");
	if (args == NULL || args[0] == NULL)
		ft_exit("Malloc error in fill_ret_args", 1);
	args[count + 1] = NULL;
	while (j < count)
	{
		if (fl == 0)
			i = i + ft_move_map_fl(map, &fl);
		else
		{
			i = i + ft_input_one_arg_1(&j,
					ft_len_one_arg(&map[i]), args, &str[i]);
			while (map[i] == 's')
				i++;
		}
	}
	return (args);
}

int	ft_set_fl(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '|')
		return (5);
	else if (map[i] == '>')
	{
		if (map[i + 1] == '>')
			return (3);
		return (1);
	}
	else if (map[i] == '<')
	{
		if (map[i + 1] == '<')
			return (4);
		return (2);
	}
	else
		return (0);
}

void	ft_input_cmd_arg(int *x, char *map, char *str, t_one_cmd_t *command)
{
	char	*temp;

	*x = ft_count_arg(map);
	command->cmd = ft_input_cmd(map, str);
	command->arg = ft_input_args(map, str, *x - 1, 0);
	temp = command->arg[0];
	command->arg[0] = command->cmd;
	if (temp)
		free(temp);
}

void	ft_fill_command(char *str, int count, char *map, t_one_cmd_t **command)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	i = 0;
	while (y < count)
	{
		command[y] = (t_one_cmd_t *)malloc(sizeof(t_one_cmd_t));
		if (command[y] == NULL)
			ft_exit("Malloc error in fill_ret_args", 1);
		x = 0;
		while (str[i] == ' ')
			i++;
		ft_input_cmd_arg(&x, &map[i], &str[i], command[y]);
		while (map[i] != '\0' && ft_strchr(SYMB, map[i]) == 0)
			i++;
		command[y]->flag = ft_set_fl(&map[i]);
		while (map[i] != '\0' && ft_strchr(SYMB, map[i]) != 0)
			i++;
		y++;
	}
}

t_one_cmd_t	**ft_do(char **str, t_list_env *envs_lsts, int count)
{
	char		*map;

	if (ft_strncmp(*str, "", 1) == 0)
		return (NULL);
	if (ft_strchr(SYMB, str[0][ft_strlen(*str) - 1]) != NULL)
	{
		ft_putstr_fd("parse error near `\\n'\n", 1);
		return (NULL);
	}
	map = (char *)ft_calloc(ft_strlen(*str) + 1, sizeof(char));
	if (map == NULL)
		ft_exit("Error malloc", 1);
	map[ft_strlen(*str)] = '\0';
	ft_make_map(*str, &map, 0, 0);
	if (ft_check_map(map, &count, 0) != 0)
	{
		ft_putstr_fd("syntax error near unexpected token `", 1);
		ft_putchar_fd(ft_check_map(map, &count, 0), 1);
		ft_putstr_fd("\'\n", 1);
		if (map)
			free(map);
		return (NULL);
	}
	return (ft_make_cmds(count, &map, str, envs_lsts));
}
