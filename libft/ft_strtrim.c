/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:12:23 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/13 03:18:56 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	x;
	unsigned int	y;
	size_t			i;
	const char		*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	y = 0;
	x = 0;
	i = ft_strlen(s1);
	s2 = s1;
	while (ft_strchr(set, (int)*s2) != NULL && *s2 != '\0')
	{
		x++;
		s2++;
	}
	if (*s2 != '\0')
	{
		s2 = s1 + i - 1;
		while (ft_strchr(set, (int)*s2--) != NULL)
			y++;
		return (ft_substr(s1, x, (size_t)(i - x - y)));
	}
	return (ft_substr(s1, x, (size_t)(x + 1)));
}
