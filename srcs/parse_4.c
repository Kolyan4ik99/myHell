/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:14:21 by grfck             #+#    #+#             */
/*   Updated: 2021/11/20 12:06:58 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_ft_make_map_check_env(char b, int q_one_fl, char c)
{
	if ((b == '$' && q_one_fl == 0)
		|| (c == '$' && q_one_fl == 0 && (ft_isdigit(b) || ft_isalpha(b)
				|| ft_strchr("_", b) != 0 || ft_strchr("?", b) != 0)))
		return (1);
	return (0);
}
