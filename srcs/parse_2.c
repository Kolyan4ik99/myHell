/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:45:21 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/20 13:56:30 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_check_map(char *map, int *count, int i)
{
	while (map[i] != '\0')
	{
		if (map[i] == 's' || map[i] == 'X' || map[i] == '_' || map[i] == '$')
			++i;
		else if (ft_strchr(SYMB, map[i]) != NULL
			&& ft_strchr(SYMB, map[i + 1]) == 0)
		{
			*count = *count + 1;
			i++;
		}
		else if (ft_check_map_char(&map[i]) && map[i + 1] != '\0')
		{
			*count = 0;
			return (map[i + 1]);
		}
		else if (ft_strchr(SYMB, map[i + 2]) != NULL && map[i + 1] != '\0')
		{
			*count = 0;
			return (map[i + 2]);
		}
		else
			i++;
	}
	*count = *count + 1;
	return (0);
}

char	*ft_find_env(char *str, t_list_env *envs_lsts)
{
	char	*res;

	while (envs_lsts != NULL)
	{
		if (!ft_strcmp(str, envs_lsts->key))
			return (envs_lsts->value);
		envs_lsts = envs_lsts->next;
	}
	res = ft_strdup("");
	if (res == NULL)
		ft_exit("Malloc error in fill_ret_args", 1);
	return (res);
}

void	ft_get_key(int *env_params, char **env_key, char *str)
{
	*env_key = (char *)ft_calloc(env_params[0], sizeof(char));
	if (*env_key == NULL)
		ft_exit("Malloc error in fill_ret_args", 1);
	ft_strlcpy(*env_key, str + env_params[1], env_params[0]);
}

void	ft_add_map_res(char **res, char *env_value, char **map, int *env_params)
{
	char	*temp_map;

	temp_map = *map;
	*res = (char *)ft_calloc(ft_strlen(env_value)
			+ ft_strlen(*map) - env_params[0] + 1, sizeof(char));
	*map = (char *)ft_calloc(ft_strlen(env_value)
			+ ft_strlen(*map) - env_params[0] + 1, sizeof(char));
	map[0][ft_strlen(env_value) + ft_strlen(temp_map)
		- env_params[0] + 1] = '\0';
	if (*res == NULL || *map == NULL)
		ft_exit("Malloc error in fill_ret_args", 1);
}

char	*ft_new_map_str(int *env_params, char **map,
		char *str, t_list_env *envs_lsts)
{
	char			*env_key;
	char			*env_value;
	char			*temp_map;
	char			*res;
	unsigned long	i;

	temp_map = *map;
	ft_get_key(env_params, &env_key, str);
	env_value = ft_find_env(env_key, envs_lsts);
	ft_add_map_res(&res, env_value, map, env_params);
	ft_strlcpy(res, str, env_params[1]);
	ft_strlcat(res, env_value, ft_strlen(env_value) + env_params[1]);
	ft_strlcat(res, str + env_params[1] + env_params[0] - 1,
		ft_strlen(str) + ft_strlen(env_value) - env_params[0] + 1);
	ft_memcpy(*map, temp_map, env_params[1] - 1);
	i = env_params[1] - 1;
	while (i < env_params[1] + ft_strlen(env_value) - 1)
		map[0][i++] = '_';
	if (temp_map + i - 2 != NULL)
		ft_memcpy(*map + ft_strlen(env_value) + env_params[1] - 1,
			temp_map + env_params[1] + env_params[0] - 1,
			ft_strlen(temp_map) - env_params[1] - env_params[0] + 1);
	free(temp_map);
	free(env_key);
	return (res);
}
