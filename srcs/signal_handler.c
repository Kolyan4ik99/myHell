/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grfck <grfck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:02:43 by cclock            #+#    #+#             */
/*   Updated: 2021/11/21 13:05:36 by grfck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	catch_sig(int sig_num)
{
	int	ret;
	int	k;

	(void)sig_num;
	k = 26;
	ret = wait(&g_signal_code);
	if (ret > 0)
	{
		if (g_signal_code == SIGINT)
			ft_return("\n", 1);
		WIFSIGNALED(g_signal_code);
		g_signal_code = 130;
		return ;
	}
	if (ret == -1)
	{
		while (k--)
			printf("\e[C");
		printf("\e[K\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ctrl_sl(int sig_num)
{
	int	k;
	int	ret;

	k = rl_end + 26;
	ret = wait(&g_signal_code);
	if (ret > 0)
	{
		WIFSIGNALED(g_signal_code);
		if (g_signal_code == SIGQUIT)
			ft_return("\nQuit from program\n", 1);
		g_signal_code = 131;
		return ;
	}
	if (sig_num == SIGQUIT)
	{
		while (k--)
			printf("\e[C");
		printf("\e[K");
	}
}

int	signal_catch(void)
{
	if (signal(SIGINT, catch_sig) == SIG_ERR)
		ft_exit("Bad init signal\n", -1);
	if (signal(SIGQUIT, ctrl_sl) == SIG_ERR)
		ft_exit("Bad init signal\n", -1);
	return (0);
}
