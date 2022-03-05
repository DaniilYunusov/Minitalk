/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:33:49 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/30 15:50:30 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	pid_print(void)
{
	ft_putstr_fd("PID --> ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

void	get_bit(char bit, int client_id)
{
	static char	sumbol = 0;
	static char	i = 0;

	sumbol += (bit << i);
	i++;
	if (i == 8)
	{
		if (sumbol == '\0')
		{
			write(1, "\n", 1);
			if (kill(client_id, SIGUSR2) == -1)
				write(1, "ERROR - bag connection with client\n", 20);
		}
		else
			write(1, &sumbol, 1);
		i = 0;
		sumbol = 0;
	}
}

void	sighandler(int sig, siginfo_t *act, void *oldact)
{
	int	client_id;

	(void)oldact;
	client_id = act->si_pid;
	if (sig == SIGUSR1)
		get_bit(1, client_id);
	else if (sig == SIGUSR2)
		get_bit(0, client_id);
}

int	main(void)
{
	struct sigaction	newact;

	newact.sa_flags = SA_SIGINFO;
	newact.sa_sigaction = sighandler;
	if (sigaction(SIGUSR1, &newact, NULL) == -1)
		errors_handling("ERROR - bad SIGUSR1\n");
	if (sigaction(SIGUSR2, &newact, NULL) == -1)
		errors_handling("ERROR - bad SIGUSR2\n");
	pid_print();
	while (42)
		pause();
	return (0);
}
