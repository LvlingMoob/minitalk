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

int	ft_parsing(int argc, char *argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "need 2 arguments: (PID) (TEXT)\n", 31);
		return (0);
	}
	while (argv[i])
	{
		if (!ft_isdigit((int)argv[i]))
		{
			write(1, "Error PID\n", 10);
			return (0);
		}
		i++;
	}
	g_data.checker = 0;
	return (1);
}
