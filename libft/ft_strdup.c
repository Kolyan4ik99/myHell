/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 03:28:03 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:40:04 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	dup[i] = '\0';
	while (--i >= 0)
		dup[i] = str[i];
	return (dup);
}
