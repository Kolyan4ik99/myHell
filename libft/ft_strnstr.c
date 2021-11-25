/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:57:05 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 11:55:17 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *a, size_t n)
{
	size_t	len_a;

	if (*a == '\0')
		return ((char *)b);
	len_a = ft_strlen(a);
	while (n >= len_a && len_a <= ft_strlen(b))
	{
		if (ft_memcmp(b, a, len_a) == 0)
			return ((char *)b);
		b++;
		n--;
	}
	return (NULL);
}
