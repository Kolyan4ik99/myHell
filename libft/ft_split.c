/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <rroxann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:04:09 by rroxann           #+#    #+#             */
/*   Updated: 2021/11/04 22:26:34 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	func1(char *s1, char c)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (*s1 != '\0')
	{
		if (*s1 == c && i != 0)
			i = 0;
		if (*s1 != c && i == 0)
		{
			i++;
			x++;
		}
		s1++;
	}
	return (x);
}

static	int	func2(char **temp, int i)
{
	if (*temp == NULL)
	{
		while (i-- > 0)
		{
			free(*temp);
			temp--;
		}
		free(*temp);
		free(temp);
		return (1);
	}
	else
		return (0);
}

static	void	func3(char **temp, char *s1, char c, int y)
{
	int	x;
	int	i;
	int	n;

	x = 0;
	i = 0;
	n = 0;
	while (i <= y)
	{
		if ((s1[i] == c && n != 0) || (s1[i] == '\0' && n != 0))
		{
			*temp = ft_substr(s1, x, n);
			if (func2(temp++, i))
				return ;
		}
		if (s1[i] == c)
			n = 0;
		if (s1[i] != c)
		{
			if (n++ == 0)
				x = i;
		}
		i++;
	}
	*temp = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (s == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (func1((char *)s, c) + 1));
	if (res == NULL)
		return (NULL);
	func3(res, (char *)s, c, (int)ft_strlen(s));
	return (res);
}
