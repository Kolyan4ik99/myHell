/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:24:25 by grfck             #+#    #+#             */
/*   Updated: 2021/11/20 13:55:31 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

t_one_cmd_t	**ft_make_cmds(int count, char **map, char **str,
			t_list_env *envs_lsts)
{
	t_one_cmd_t	**commands;

	commands = (t_one_cmd_t **)malloc(sizeof(t_one_cmd_t) * (count + 1));
	if (commands == NULL)
		ft_exit("Error malloc", 1);
	commands[count] = NULL;
	ft_input_ens(map, str, envs_lsts);
	*str = ft_clean_fr_q(*str, map);
	ft_fill_command(*str, count, *map, commands);
	if (*map)
		free(*map);
	ft_mix(commands);
	return (commands);
}
