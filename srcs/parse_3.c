/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:46:29 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/20 13:54:01 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_input_ens(char **map, char **str, t_list_env *envs_lsts)
{
	int			i;
	int			env_params[2];
	char		*temp;

	i = 0;
	while (map[0][i] != '\0')
	{
		env_params[0] = 0;
		if (map[0][i] == '$')
		{
			while (map[0][i] == '$')
			{
				i++;
				env_params[0] = env_params[0] + 1;
			}
			temp = *str;
			env_params[1] = i - env_params[0] + 1;
			*str = ft_new_map_str(env_params, map, *str, envs_lsts);
			free(temp);
		}
		else
			i++;
	}
}

int	ft_make_map_check_q(int *q_one_fl, int *q_two_fl, char c)
{
	if (*q_one_fl == 0 && *q_two_fl == 0 && c == '\'')
	{
		*q_one_fl = 1;
		return (1);
	}
	else if (*q_one_fl == 0 && *q_two_fl == 0 && c == '\"')
	{
		*q_two_fl = 1;
		return (1);
	}
	else if (*q_one_fl == 1 && *q_two_fl == 0 && c == '\'')
	{
		*q_one_fl = 0;
		return (1);
	}
	else if (*q_one_fl == 0 && *q_two_fl == 1 && c == '\"')
	{
		*q_two_fl = 0;
		return (1);
	}
	else
		return (0);
}

void	ft_make_map(char *str, char **map, int q_one_fl, int q_two_fl)
{
	int	b;

	b = 0;
	while (str[b] != '\0')
	{
		if (ft_make_map_check_q(&q_one_fl, &q_two_fl, str[b]) == 1)
			map[0][b++] = 'X';
		else if (str[b] == ' ' && q_one_fl == 0 && q_two_fl == 0)
		{
			while (str[b] == ' ')
				map[0][b++] = 's';
		}
		else if (ft_ft_make_map_check_env(str[b], q_one_fl,
				map[0][b - 1]))
			map[0][b++] = '$';
		else
		{
			if (ft_strchr(SYMB, str[b]) != NULL && q_one_fl == 0
				&& q_two_fl == 0)
				map[0][b] = str[b];
			else
				map[0][b] = '_';
			b++;
		}
	}
}

void	ft_clean_do_map_res(char **map, char **res, int *count, int i)
{
	while (map[0][i] != '\0')
	{
		if (map[0][i] != 'X')
			*count = *count + 1;
		i++;
	}
	*res = (char *)ft_calloc(*count + 1, sizeof(char));
	*map = (char *)ft_calloc(*count + 1, sizeof(char));
	if (*res == NULL || *map == NULL)
		ft_exit("Malloc error in fill_ret_args", 1);
	res[0][*count] = '\0';
	map[0][*count] = '\0';
}

char	*ft_clean_fr_q(char *str, char **map)
{
	char	*res;
	int		i;
	int		j;
	int		count;
	char	*temp_map;

	i = 0;
	j = 0;
	count = 0;
	temp_map = *map;
	ft_clean_do_map_res(map, &res, &count, 0);
	while (j < count)
	{
		if (temp_map[i] == 'X')
			i++;
		else
		{
			res[j] = str[i];
			map[0][j++] = temp_map[i++];
		}
	}
	free(str);
	free(temp_map);
	return (res);
}
