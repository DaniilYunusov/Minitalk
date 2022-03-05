/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:31:49 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/30 15:52:49 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		while (*s)
			write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	dec;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 0 && n <= 9)
	{
		dec = n + '0';
		write(fd, &dec, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}

void	errors_handling(char *string)
{
	ft_putstr_fd(string, 1);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	finish;

	sign = 1;
	finish = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		finish = (finish * 10 + (*str - '0'));
		str++;
	}
	if ((finish >= 9223372036854775807) && sign == 1)
		return (-1);
	if ((finish >= 9223372036854775807) && sign == -1)
		return (0);
	return ((int)finish * sign);
}
