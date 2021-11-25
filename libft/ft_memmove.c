/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:31:31 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:37:57 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src > dst && (src != NULL || dst != NULL))
	{
		while (i < n)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	if (src < dst && (src != NULL || dst != NULL))
	{
		while (n-- > i)
			*((char *)dst + n) = *((char *)src + n);
	}
	return (dst);
}
