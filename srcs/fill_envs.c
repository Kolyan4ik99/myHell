/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <cclock@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:16:54 by cclock            #+#    #+#             */
/*   Updated: 2021/11/18 21:56:17 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_fill_key_envs_lists(int *x, int i, char **key, char **env)
{
	*x = ft_strrchr(env[i], '=') - &env[i][0];
	*key = (char *)ft_calloc(*x + 1, sizeof(char));
	if (*key == NULL)
		ft_exit("Malloc плохо сработаль", -1);
	ft_strlcpy(*key, env[i], *x + 1);
}

void	ft_fill_value_envs_lists(int *x, int i, char **value, char **env)
{
	*value = (char *)ft_calloc(ft_strlen(env[i]) - *x, sizeof(char));
	if (*value == NULL)
		ft_exit("Malloc плохо сработаль", -1);
	ft_strlcpy(*value, &env[i][*x + 1], ft_strlen(env[i]) - *x);
}

t_list_env	*ft_envs_lists(char **env, int i, int x)
{
	t_list_env	*temp;
	t_list_env	*start;
	char		*key_temp;
	char		*value_temp;

	i = 0;
	x = 0;
	ft_fill_key_envs_lists(&x, i, &key_temp, env);
	ft_fill_value_envs_lists(&x, i, &value_temp, env);
	temp = ft_lstnew_env(key_temp, value_temp);
	start = temp;
	while (env[++i])
	{
		ft_fill_key_envs_lists(&x, i, &key_temp, env);
		ft_fill_value_envs_lists(&x, i, &value_temp, env);
		temp->next = ft_lstnew_env(key_temp, value_temp);
		temp = temp->next;
	}
	return (start);
}
