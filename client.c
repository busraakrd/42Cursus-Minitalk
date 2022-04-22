/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaraden <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:05:54 by bkaraden          #+#    #+#             */
/*   Updated: 2022/03/31 14:42:38 by bkaraden         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		res = (res * 10) + (*str++ - '0');
	}
	return (res);
}

void	chartobit(char c, int servpid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			kill(servpid, SIGUSR1);
		}
		else
		{
			kill(servpid, SIGUSR2);
		}
		i++;
		usleep(100);
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR2)
	{
		write(1, "SENT", 4);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					servpid;
	char				*str;

	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR2, &sa, 0);
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	servpid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		chartobit(*str, servpid);
		str++;
	}
	return (0);
}
