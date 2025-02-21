/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:15:28 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/21 15:41:23 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_smaller_count(t_stack *stack, int *values, int nb)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (i < stack->len)
	{
		if (values[i] < nb)
		{
			counter++;
			if (counter == stack->len - 1)
				break ;
		}
		i++;
	}
	return (counter);
}

static void	*value_creation(t_stack *stack, int *values)
{
	int	*values;

	values = (int *)ft_calloc(stack->len, sizeof(int));
	if (!values)
	{
		stack->error = 1;
		return ; 
	}
	ft_memcpy(values, stack->values, (stack->len * sizeof(int)));
}

void	index_convert(t_stack *stack)
{
	int	i;
	int	count_smaller;
	int	*values;

	values = value_creation(stack, &values,);
	i = 0;
	while (i < stack->len)
	{
		count_smaller = get_smaller_count(stack, values, values[i]);
		stack->values[i] = count_smaller;
		i++;
	}
	free(values);
}
