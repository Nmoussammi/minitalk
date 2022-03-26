/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:22:44 by nmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 19:41:22 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s);
void	ft_putnbr(int pid);
int		ft_atoi(char *str);
void	send_signals(char ch, int pid);
void	send_message(char *str, int pid);
void	handler(char *c, int *bit, int new_pid);
void	handler_sigusr(int signum, siginfo_t *siginf, void *unused);

#endif
