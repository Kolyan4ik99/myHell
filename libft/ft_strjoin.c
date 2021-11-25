/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:20:25 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:40:15 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		res = ft_strdup(s2);
	else if (s2 == NULL)
		res = ft_strdup(s1);
	else
	{
		res = (char *)malloc(sizeof(char)
				* (1 + (int)ft_strlen(s1) + (int)ft_strlen(s2)));
		if (res == NULL)
			return (NULL);
		ft_memcpy(res, s1, (int)ft_strlen(s1));
		ft_memcpy(res + (int)ft_strlen(s1), s2, (int)ft_strlen(s2) + 1);
	}
	return (res);
}
