/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll_long_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:59:06 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:55:12 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static void	sign_treatment(t_stack *stack, int *countsign, long long *result)
{
	if (*countsign == (-1))
	{
		*result = ((*result) * (*countsign));
		if (*result < INT_MIN)
			push_swap_exit(stack, "Input error: Value smaller than INT_MIN!\n");
	}
	if (*result > INT_MAX)
		push_swap_exit(stack, "Input error: Value bigger than INT_MAX!\n");
}

static void	pre_numb_parse(t_stack *stack, const char **str, int *countsign)
{
	while (**str && ((9 <= **str && **str <= 13) || **str == ' '))
		str++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*countsign = -(*countsign);
		(*str)++;
		if (**str == '-' || **str == '+')
			push_swap_exit(stack, "Input error: multiple signs in input.\n");
	}
}

int	atoll_push_swap(t_stack *stack, const char *str)
{
	long long	result;
	int			countsign;

	countsign = 1;
	result = 0;
	pre_numb_parse(stack, &str, &countsign);
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	sign_treatment(stack, &countsign, &result);
	return (result);
}
