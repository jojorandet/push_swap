/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/07 19:21:52 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_exit(t_stack *stack, int	*cursor, int median)
{
	while (cursor <= stack->end)
	{
		if (*cursor <= median)
			return (1);
		cursor++;
	}
	return (0);
}

static void	sort_with_median(t_stack *stack, t_string *string, int median)
{
	int	*cursor;
	int	still_smaller_to_check;

	cursor = stack->values;
	still_smaller_to_check = 1;
	while (still_smaller_to_check)
	{
		if (*cursor <= median)
		{
			push_b(stack, string);
			cursor++;
		}
		else
		{
			rot_a(stack, string);
			still_smaller_to_check = check_exit(stack, cursor, median);
		}
	}
	// printf("the array after sorting according to the median is:\n\n");
	// print_array(stack);
}

int	find_median(t_stack *stack)	
{
	if (stack->len % 2 == 0)
		return ((stack->len / 2) - 1);
	return (stack->len / 2);
}

void	prepare_sort(t_stack *stack, t_string *string)
{
	(void)string;
	int	median;
	
	median = find_median(stack);
	sort_with_median(stack, string, median);
}


//with the indesx sorting, i can easily find the median as well as the values above or below it :)
//explore the use of indexes and play around with this idea,
//calculate the cost of the operations and move forward in that manner
//then once you've found this strategy, rename then into pivot, and recursively split the array into smaller chunks

// I can use len - 1 and the indexes to find the median value
//once i have the median, then i can do all my operations
//depending on where the median is, then it will change the procedure
//calculate the cost of a ra move and the rra move and compare them one another. 


/*
static void	sort_with_median(t_stack *stack, t_string *string, int median)
{
	int	*cursor;
	int n;

	printf("median value is %d\n\n", median);
	n = (stack->len + 1);
	cursor = stack->values;
	while(n)
	{
		if (*cursor <= median)
		{
			push_b(stack, string);
			cursor = stack->top;
		}
		else if (*cursor > median)
		{
			rot_a(stack);
			
		}
		n--;
	}

	print_array(stack);
}*/