/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:32:18 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/30 15:47:34 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	errors_handling(char *string);
int		ft_atoi(const char *str);

#endif
