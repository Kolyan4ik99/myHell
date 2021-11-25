/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:44:58 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:41:56 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&str[i]);
	while (--i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
	}
	return (NULL);
}
