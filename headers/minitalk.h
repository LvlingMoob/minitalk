/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberengu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:19:38 by mberengu          #+#    #+#             */
/*   Updated: 2021/09/24 16:19:44 by mberengu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_server
{
	char	*arg2;
	int		pid;
	int		checker;
}				t_server;

t_server	g_data;

char	*ft_strdup(char *src);
void	*ft_calloc(int nmemb, int size);
int		ft_atoi(const char *str);
int		ft_parsing(int argc, char *argv);
void	ft_putnbr(long int nbr);

#endif
