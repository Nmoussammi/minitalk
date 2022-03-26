/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:22:29 by nmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 21:06:11 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(char ch, int pid)
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

void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signals(str[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("invalid arguments\n");
		ft_putstr("correct format : ./client PID_SERVER MESSAGE");
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (write (2, "ERROR", 5), 0);
	send_message(argv[2], pid);
	return (0);
}
