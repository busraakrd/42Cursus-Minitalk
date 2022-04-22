/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaraden <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:07:19 by bkaraden          #+#    #+#             */
/*   Updated: 2022/03/31 13:09:11 by bkaraden         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	receive_string(int signum, siginfo_t *siginfo, void *context);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	chartobit(char c, int servpid);

#endif
