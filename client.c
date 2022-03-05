/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:32:45 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/30 15:46:59 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sending_a_char(unsigned char symbol, int pid)
{
	int	mask;

	mask = 1;
	while (mask <= 128)
	{
		if ((mask & symbol) > 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				errors_handling("Contact with this server is not possible!\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				errors_handling("Contact with this server is not possible!\n");
		}
		mask *= 2;
		usleep(65);
	}
}

void	sending_a_signals(char *process_id, char *message)
{
	int	pid;
	int	i;

	pid = ft_atoi(process_id);
	i = 0;
	while (message[i])
	{
		sending_a_char(message[i], pid);
		i++;
	}
	sending_a_char(message[i], pid);
}

void	ft_close_client(int sig)
{
	(void)sig;
	exit(0);
}

int	main(int argv, char **argc)
{
	if (argv != 3)
		errors_handling("Incorrect number of arguments!\n");
	signal(SIGUSR2, ft_close_client);
	sending_a_signals(argc[1], argc[2]);
	while (42)
		pause();
	return (0);
}
