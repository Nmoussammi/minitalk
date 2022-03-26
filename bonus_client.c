/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:24:12 by nmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 21:59:02 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

void	msg_handler1(int signum)
{
	if (signum == 30)
		ft_putstr("\nMessage successfully sent...");
}

void	send_signals1(char ch, int pid)
{
	int	shift;

	shift = -1;
	while (++shift < 8)
	{
		if (ch & (128 >> shift))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (1);
		}
		usleep(900);
	}
}

void	send_message1(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signals1(str[i], pid);
		i++;
	}
	send_signals1('\0', pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, msg_handler1);
	if (argc != 3)
	{
		ft_putstr("invalid arguments");
		ft_putstr("correct format : ./client PID_SERVER MESSAGE");
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (write (2, "ERROR", 5), 0);
	send_message1(argv[2], pid);
	while (1)
		pause ();
	return (0);
}
