/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minitalk.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:24:32 by nmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 19:25:42 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MINITALK_H
# define BONUS_MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s);
void	ft_putnbr(int pid);
int		ft_atoi(char *str);
void	msg_handler1(int signum);
void	send_signals1(char ch, int pid);
void	send_message1(char *str, int pid);
void	handler1(char *c, int *bit, int new_pid);
void	handler_sigusr1(int signum, siginfo_t *siginf, void *unused);

#endif
