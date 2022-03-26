/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:42 by nmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 21:06:51 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

void	ft_putnbr(int pid)
{
	int	rest;
	int	nbr;

	nbr = pid;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	rest = nbr % 10 + '0';
	nbr /= 10;
	if (nbr != 0)
		ft_putnbr(nbr);
	write(1, &rest, 1);
}

int	ft_atoi(char *str)
{
	int			i;
	int			signe;
	long int	nb;

	i = 0;
	signe = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (signe == -1)
		return (signe * nb);
	else
		return (nb);
}
