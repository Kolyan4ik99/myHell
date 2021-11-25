/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:47:26 by grfck             #+#    #+#             */
/*   Updated: 2021/11/20 13:50:07 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_lstsize_env(t_list_env *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_fill_s_k(t_list_env *list, int i, char **s_k)
{
	while (list != NULL)
	{
		s_k[i] = list->key;
		list = list->next;
		i++;
	}
}

void	ft_print_export(int count, char **s_k, t_list_env *list)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strncmp(s_k[i], "?", 1) == 0)
			i++;
		else
		{
			printf("declare -x %s=\"%s\"\n", s_k[i], ft_find_env(s_k[i], list));
			i++;
		}
	}
	if (s_k)
		free(s_k);
}

void	ft_sort_export(int count, char **s_k)
{
	int		n;
	int		i;
	char	*max;

	n = 0;
	while (n < count)
	{
		i = 0;
		while (i < count - n - 1)
		{
			if (ft_strncmp(s_k[i], s_k[i + 1], ft_strlen(s_k[i])) > 0)
			{
				max = s_k[i];
				s_k[i] = s_k[i + 1];
				s_k[i + 1] = max;
			}
			i++;
		}
		n++;
	}
}

void	ft_sort_print_envs(t_list_env *list, int count)
{
	char	**s_k;

	count = ft_lstsize_env(list);
	s_k = (char **)malloc(sizeof(char *) * (count + 1));
	if (s_k == NULL)
		ft_exit("Error malloc", 1);
	s_k[count] = NULL;
	ft_fill_s_k(list, 0, s_k);
	ft_sort_export(count, s_k);
	ft_print_export(count, s_k, list);
}
