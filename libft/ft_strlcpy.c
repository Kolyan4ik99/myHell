/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:14:37 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:40:39 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	i = ft_strlen(src);
	if (n == 0)
		return (i);
	while (--n != 0 && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}
