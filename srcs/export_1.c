/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:48:08 by grfck             #+#    #+#             */
/*   Updated: 2021/11/21 21:42:26 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_make_new_env(char *temp, char *str, char **key, char **value)
{
	ft_make_new_env_kv(key, str - temp, temp);
	temp = str;
	while (*str != '\0')
		str++;
	if (str == temp)
		*value = "";
	else
		ft_make_new_env_kv(value, str - temp + 1, temp);
}

void	ft_make_new_env_kv(char **res, int len, char *start)
{
	*res = (char *)ft_calloc(len, sizeof(char));
	if (*res == NULL)
		ft_exit("Error malloc", 1);
	(*res)[len - 1] = '\0';
	ft_strlcpy(*res, start, len);
}

int	ft_check_new_env(char *str, int i)
{
	if (*str == '=')
		return (1);
	while (str[i] != '=' && str[i] != '\0')
	{
		if (i == 0 && ft_isdigit(str[i]))
			return (1);
		else if (ft_isalnum(str[i]) || ft_strchr("_", str[i]) != 0)
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_parse_new_env(char *str, char **key, char **value)
{
	char	*temp;

	temp = str;
	if (ft_check_new_env(str, 0))
	{
		printf("export: `%s': not a valid identifier\n", str);
		return (0);
	}
	while (*str != '=' && *str != '\0')
		str++;
	if (*str++ == '\0')
	{
		*key = ft_strdup(temp);
		if (!*key)
			ft_exit("Bad malloc\n", -1);
		*value = ft_strdup("");
		if (!*value)
			ft_exit("Bad malloc\n", -1);
	}
	else
		ft_make_new_env(temp, str, key, value);
	return (1);
}
