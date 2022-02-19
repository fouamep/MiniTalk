/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:50:12 by fbouanan          #+#    #+#             */
/*   Updated: 2022/02/17 13:50:14 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		ss1;
	int		ss2;
	char	*m;

	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	m = malloc(sizeof(char) * (ss1 + ss2 + 1));
	if (!m)
		return (0);
	i = 0;
	while (i <= ss1)
	{
		m[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ss2)
		m[ss1++] = s2[i++];
	m[ss1] = '\0';
	return (m);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ' )
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
