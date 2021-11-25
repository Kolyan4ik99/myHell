/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:25:23 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:35:22 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buff, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)buff + i) == c)
			return ((char *)buff + i);
		i++;
	}
	return (NULL);
}
