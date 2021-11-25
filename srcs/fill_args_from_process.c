/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args_from_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroxann <rroxann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:36:08 by cclock            #+#    #+#             */
/*   Updated: 2021/11/06 00:47:10 by rroxann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_exit(char *code, int err_code)
{
	write(1, code, ft_strlen(code));
	exit(err_code);
}

int	ft_return(char *code, int err_code)
{
	write(1, code, ft_strlen(code));
	return (err_code);
}
