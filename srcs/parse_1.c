/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:41:58 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/20 13:56:41 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_count_arg(char *map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (ft_strchr(SYMB, map[i]) == 0 && map[i] != '\0')
	{
		if (map[i] == 's')
		{
			count++;
			while (map[i] == 's')
				i++;
		}
		else
			i++;
	}
	if ((map[i] == '\0' || ft_strchr(SYMB, map[i]) != 0) && map[i - 1] != 's')
		count++;
	return (count);
}

char	*ft_input_cmd(char *map, char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (map[i] != '\0' && ft_strchr(SYMB, map[i]) == 0 && map[i] != 's')
		i++;
	if (i == 0)
		res = ft_strdup("");
	else
	{
		res = (char *)ft_calloc(i + 1, sizeof(char));
		ft_strlcpy(res, str, i + 1);
	}
	if (res == NULL)
		ft_exit("Malloc error in fill_ret_args", 1);
	return (res);
}

int	ft_len_one_arg(char *map)
{
	int	x;

	x = 0;
	while (map[x] != 's' && map[x] != '\0'
		&& ft_strchr(SYMB, map[x]) == 0)
		x++;
	return (x);
}

int	ft_input_one_arg_1(int *j, int x, char **args, char *str)
{
	int	i;

	i = 0;
	args[*j + 1] = (char *)ft_calloc(x + 1, sizeof(char));
	if (args[*j + 1] == NULL)
		ft_exit("Malloc error in fill_ret_args", 1);
	ft_strlcpy(args[*j + 1], str, x + 1);
	*j = *j + 1;
	return (i + x);
}

int	ft_move_map_fl(char *map, int *fl)
{
	int	i;

	i = 0;
	while (map[i] != 's')
		i++;
	while (map[i] == 's')
		i++;
	*fl = 1;
	return (i);
}
