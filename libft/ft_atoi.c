/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:34:56 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/08 17:10:18 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		countsign;

	countsign = 1;
	result = 0;
	while (*str && ((9 <= *str && *str <= 13) || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			countsign = -countsign;
		str++;
	}
	if (*str == '-' || *str == '+')
		return (INT_MAX);
	while ('0' <= *str && *str <= '9')
	{
		if ((result * 10) / 10 != result)
		{
			if (countsign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	if (countsign == -1)
	{
		result = (countsign * result);
		if (result < INT_MIN)
			return (INT_MIN);
	}
	if (result > INT_MAX)
		return (INT_MAX);
	return (result);
}
