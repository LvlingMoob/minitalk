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

void	char_dealer(int pid)
{
	static int	pos = 0;
	static int	i = 0;

	if (g_arg2[pos])
	{
		if ((g_arg2[pos] >> i) & 1)
		{	
			if (kill(pid, SIGUSR1) == -1)
				prog_end();
		}
		else
		{	
			if (kill(pid, SIGUSR2) == -1)
				prog_end();
		}
		i++;
		if (i == 8)
		{
			pos += 1;
			i = 0;
		}
	}
	else
		prog_end();
}

void	sig_dealer(int sign, siginfo_t *info, void *context)
{
	(void)context;
	usleep(50);
	if (sign == SIGUSR2)
		char_dealer(info->si_pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sig_dealer;
	sigaction(SIGUSR2, &sig, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		g_arg2 = ft_strdup(argv[2]);
		if (ft_parsing(argv[1], pid))
		{
			char_dealer(pid);
			while (1)
				pause();
		}
	}
	else
	{
		write(1, "need 2 arguments: (PID) (TEXT)\n", 31);
		prog_end();
	}
	return (0);
}
