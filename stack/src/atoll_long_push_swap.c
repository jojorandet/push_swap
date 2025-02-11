/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll_long_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:59:06 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/10 16:13:12 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	sign_treatment(t_stack *stack, int *countsign, long long *result)
{
	if (*countsign == -1)
	{
		if (*result < INT_MIN)
		{
			*result = ((*result) * (*countsign));
			push_swap_exit(stack, "Input error: Value smaller than INT_MIN!\n");
		}
	}
	if (*result > INT_MAX)
		push_swap_exit(stack, "Input error: Value bigger than INT_MAX!\n");
}

static void	pre_number_parse(t_stack *stack, const char **str, int *countsign)
{
	printf("pre numbers parse entered\n");
	while (**str && ((9 <= **str && **str <= 13) || **str == ' '))
		str++;
	printf("address of variable pointed by *str is %p\n", str);
	printf("valéue pointed by str is %d\n", **str);
	while (**str == '-' || **str == '+')
	{
		printf("while loop entered\n");
		if (**str == '-')
			*countsign = -(*countsign);
		(*str)++;
		printf("address of variable pointed by *str++ is %p\n", str);
		printf("value pointed by str in while is %d\n", **str);
		if (**str == '-' || **str == '+')
			push_swap_exit(stack, "Input error: multiple signs in input.\n");
	}
	
}

int	atoll_push_swap(t_stack *stack, const char *str)
{
	long long	result;
	int			countsign;

	printf("atoll funciton entered\n");
	printf("input is %s\n", str);
	countsign = 1;
	result = 0;
	pre_number_parse(stack, &str, &countsign);
	printf("the value of result after prenumberparse is %s\n", str);
	printf("the value pointed by str is %d\n", *str);
	while ('0' <= *str && *str <= '9')
	{
		printf("while loop entered\n");
		if ((result * 10) / 10 != result)
		{
			if (countsign == 1)
				push_swap_exit(stack, "Input error: Overflow detected!\n");
			else if (countsign == -1)
				push_swap_exit(stack, "Input error: Overflow detected!\n");
		}
		result = (result * 10) + (*str - 48);
		printf("\n\nthe value of result inside while loop is %lld\n\n", result);
		str++;
	}
	printf("the value of result after while loop is %lld\n", result);
	sign_treatment(stack, &countsign, &result);
	printf("the value of result after atoll is %lld\n", result);
	return (result);
}
