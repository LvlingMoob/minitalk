/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberengu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:19:10 by mberengu          #+#    #+#             */
/*   Updated: 2021/09/24 16:19:13 by mberengu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	prog_end(int from)
{
	if (from == 1)
		write(1, "no response from server\n", 24);
	free(g_data.arg2);
	exit(0);
}

void	char_dealer(int pid)
{
	static int	pos = 0;
	static int	i = 0;

	if (g_data.arg2[pos])
	{
		if ((g_data.arg2[pos] >> i) & 1)
		{	
			if (kill(pid, SIGUSR1) == -1)
				return ;
		}
		else
		{	
			if (kill(pid, SIGUSR2) == -1)
				return ;
		}
		i++;
		if (i == 8)
		{
			pos += 1;
			i = 0;
		}
	}
	else
		prog_end(0);
}

void	sig_dealer(int sign, siginfo_t *info, void *context)
{
	(void)context;
	g_data.checker = 1;
	usleep(50);
	if (info->si_pid == g_data.pid && sign == SIGUSR2)
		char_dealer(info->si_pid);
}

int	main(int argc, char **argv)
{
	int					returnchecker;
	struct sigaction	sig;

	returnchecker = 1;
	if (ft_parsing(argc, argv[1]))
	{
		sig.sa_flags = SA_SIGINFO;
		sig.sa_sigaction = sig_dealer;
		g_data.pid = ft_atoi(argv[1]);
		g_data.arg2 = ft_strdup(argv[2]);
		char_dealer(g_data.pid);
		sigaction(SIGUSR2, &sig, NULL);
		while (returnchecker)
		{
			sleep(1);
			if (g_data.checker == 0)
				prog_end(1);
			pause();
		}
	}
}
