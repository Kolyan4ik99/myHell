/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:30:50 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:42:17 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;

	if (str == NULL)
		return (NULL);
	res = (char *)malloc(((int)len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(str) || str == NULL || *str == '\0')
		return (res);
	ft_memcpy(res, str + start, len);
	*(res + len) = '\0';
	return (res);
}
