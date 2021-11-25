/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:09:24 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/11 00:32:21 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*m;
	size_t	i;

	i = 0;
	m = (void *)malloc(n * s);
	if (m == NULL)
		return (NULL);
	while (i < n * s)
	{
		*((char *)m + i) = 0;
		i++;
	}
	return (m);
}
