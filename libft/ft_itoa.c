/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:48:53 by rroxann           #+#    #+#             */
/*   Updated: 2020/11/14 16:23:53 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_count(int n, int *len)
{
	if (n <= 0)
		*len = *len + 1;
	while (n != 0)
	{
		*len = *len + 1;
		n /= 10;
	}
}

static int	ft_checker(int n)
{
	if (n == 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		x;

	len = 0;
	ft_count(n, &len);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	x = ft_checker(n);
	while (len != 0)
	{
		if (n > 0)
			res[len - 1] = n % 10 + '0';
		else
		{
			if (len - 1 == 0 && x == 0)
				*res = '-';
			else
				res[len - 1] = -(n % 10) + '0';
		}
		n /= 10;
		len--;
	}
	return (res);
}
