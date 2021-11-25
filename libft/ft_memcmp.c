/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:35:55 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 11:15:50 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)buf1 + i) == *((unsigned char *)buf2 + i))
			i++;
		else if (*((unsigned char *)buf1 + i) > *((unsigned char *)buf2 + i))
			return (*((unsigned char *)buf1 + i)
				- *((unsigned char *)buf2 + i));
		else if (*((unsigned char *)buf1 + i) < *((unsigned char *)buf2 + i))
			return (*((unsigned char *)buf1 + i)
				- *((unsigned char *)buf2 + i));
	}
	return (0);
}
