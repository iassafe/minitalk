/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:06:59 by iassafe           #+#    #+#             */
/*   Updated: 2023/03/12 13:16:54 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

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

void	print_msg(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr("lmsg wsal lserver\n");
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
	signal(SIGUSR1, print_msg);
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
	if (av[2][i] == '\0')
		ft_send(pid, av[2][i]);
}
