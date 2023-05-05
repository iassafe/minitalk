/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:43:29 by iassafe           #+#    #+#             */
/*   Updated: 2023/03/12 13:44:54 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signum, siginfo_t *info, void *secret)
{
	static unsigned char	k;
	static int				i;
	static int				pidclient;
	int						stock;

	(void)secret;
	if (pidclient != info->si_pid)
	{
		pidclient = info->si_pid;
		k = 0;
		i = 0;
	}
	stock = 0;
	if (signum == SIGUSR1)
		stock = 1;
	k = (k << 1) | stock;
	i++;
	if (i == 8)
	{
		if (k == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &k, 1);
		i = 0;
		k = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("server pid: ");
	ft_putnbr(getpid());
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putchar('\n');
	while (1)
		pause();
}
