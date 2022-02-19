/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:46:18 by fbouanan          #+#    #+#             */
/*   Updated: 2022/01/04 12:46:21 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_pid(char	*to_check)
{
	int	i;

	i = 0;
	while (to_check[i])
	{
		if (!('0' <= to_check[i] && to_check[i] <= '9'))
			return (-1);
		i++;
	}
	return (ft_atoi(to_check));
}

static void	main_send(char *s, int bit, int i, int pid)
{
	while (bit < 8)
	{
		if ((s[i] >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error fouad", 1);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error Boua", 1);
				exit(1);
			}
		}
		bit++;
		usleep(100);
	}
}

void	send_data(int pid, char *string_to_send)
{
	int	len;
	int	i;
	int	bit;

	len = ft_strlen(string_to_send);
	i = 0;
	while (i < len)
	{
		bit = 0;
		main_send(string_to_send, bit, i, pid);
		i++;
	}
	free(string_to_send);
}

int	main(int ac, char **av)
{
	int	serv_pid;

	(void) av;
	if (ac != 3)
	{
		ft_putstr_fd("INPUT ERROR!", 1);
		exit(1);
	}
	if (check_pid(av[1]) == -1)
	{
		ft_putstr_fd("INVALID PID", 1);
		exit(1);
	}
	serv_pid = check_pid(av[1]);
	if (serv_pid <= 0 || serv_pid > 99999)
	{
		ft_putstr_fd("INVALID PID", 1);
		exit(1);
	}
	else
	{
		send_data(serv_pid, ft_strjoin(av[2], "\n"));
	}
}
