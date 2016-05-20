/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:27:36 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/20 10:05:18 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' '|| str[i] == '\t' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == ft_strlen(str))
		return (1);
	ft_error();
	return (0);
}

int		ft_atoi(char *str)
{
	long	sign;
	long	nbr;

	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' ||
			*str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nbr = 0;
	while (ft_isdigit((int)*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if (!(sign * nbr <= 2147483647 && sign * nbr >= -2147483648) ||
		ft_check_digit(str) != 1)
		ft_error();
	return (sign * nbr);
}
