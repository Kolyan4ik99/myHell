/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:33:07 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:40:26 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	while (n != 0 && *dst != '\0')
	{
		n--;
		i++;
		dst++;
	}
	if (n == 0)
		return (j + i);
	n--;
	while (n != 0 && *src != '\0')
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	return (i + j);
}
