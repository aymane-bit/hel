/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:28:12 by akajjou           #+#    #+#             */
/*   Updated: 2024/04/01 13:21:40 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_int_error(long digits)
{
	if (digits < -2147483648 || digits > 2147483647)
	{
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	digits;
	int		a;

	sign = 1;
	digits = 0;
	a = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		digits = digits * 10 + sign * (*str - 48);
		str++;
		a++;
	}
	ft_check_int_error(digits);
	return (digits);
}
