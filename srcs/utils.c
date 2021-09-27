/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberengu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:30:52 by mberengu          #+#    #+#             */
/*   Updated: 2021/09/24 17:30:54 by mberengu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	prog_end(void)
{
	free(g_arg2);
	exit(0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr / 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_parsing(char *argv, int pid)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit((int)argv[i]))
		{
			write(1, "Error PID\n", 10);
			prog_end();
		}
		i++;
	}
	if (kill(pid, 0) != 0)
	{
		write(1, "BAD PID\n", 8);
		prog_end();
	}
	return (1);
}
