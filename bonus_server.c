/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:24:48 by nmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 21:05:52 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

int	g_pid;

void	handler1(char *c, int *bit, int new_pid)
{
	*c = 0xFF;
	*bit = 0;
	g_pid = new_pid;
}

void	handler_sigusr1(int signum, siginfo_t *siginf, void *unused)
{
	static char	c = 0xFF;
	static int	bit;

	(void)unused;
	if (g_pid != siginf->si_pid)
		handler1(&c, &bit, siginf->si_pid);
	if (signum == SIGUSR1)
		c ^= 128 >> bit;
	else if (signum == SIGUSR2)
		c |= 128 >> bit;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(siginf->si_pid, SIGUSR1);
		write(1, &c, 1);
		bit = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_sigusr1;
	sa.sa_flags = SA_RESTART;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
