/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaraden <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:06:37 by bkaraden          #+#    #+#             */
/*   Updated: 2022/03/31 14:53:08 by bkaraden         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr (nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_putchar((nbr % 10) + 48);
}

void	receive_string(int signum, siginfo_t *siginfo, void *context)
{
	static char	c = 0;
	static char	i = 0;

	(void)context;
	if (signum == SIGUSR1)
	{
		c += 1 << i;
		i++;
	}
	else if (signum == SIGUSR2)
		i++;
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					servpid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &receive_string;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	servpid = getpid();
	ft_putnbr(servpid);
	while (1)
		pause();
	return (0);
}
