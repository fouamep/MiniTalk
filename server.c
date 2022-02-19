/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:46:30 by fbouanan          #+#    #+#             */
/*   Updated: 2022/01/04 12:46:31 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_data(int sig)
{
	static char	print_char;
	static int	size;

	print_char += ((sig % 2) << size);
	size++;
	if (size == 8)
	{
		ft_putchar_fd(print_char, 1);
		print_char = 0;
		size = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server Pid is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, receive_data);
		signal(SIGUSR2, receive_data);
		pause();
	}
}
