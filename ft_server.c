/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:19:56 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/03 12:16:28 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *secret)
{
	int						stock;
	static unsigned char	k;
	static int				i;
	static int				pidclient;

	(void)secret;
	if (pidclient != info->si_pid)
	{
		pidclient = info->si_pid;
		k = 0;
		i = 0;
	}
	if (signum == SIGUSR2)
		stock = 0;
	if (signum == SIGUSR1)
		stock = 1;
	k = (k << 1) | stock;
	i++;
	if (i == 8)
	{
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
