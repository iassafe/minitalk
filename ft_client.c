/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:35:58 by iassafe           #+#    #+#             */
/*   Updated: 2023/03/13 11:57:18 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	ft_send(int pid, char c)
{
	int		i;
	char	k;

	i = 7;
	while (i >= 0)
	{
		k = c >> i;
		if ((k & 1) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(900);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("khass darouri ykon ac = 3\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		ft_putstr("khass darouri ykon pid positif\n");
		exit(1);
	}
	while (av[2][i])
	{
		ft_send(pid, av[2][i]);
		i++;
	}
}
