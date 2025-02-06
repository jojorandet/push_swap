/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/06 08:25:24 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_smallest_a(t_stack *stack)
{
	int	*cursor;
	int	current_min;
	int	count;
	int	min_pos;

	cursor = stack->top;
	count = 0;
	min_pos = 0;
	current_min = *cursor;
	while (cursor && (cursor != (stack->end + 1)))
	{
		if (current_min > *cursor)
		{
			current_min = *cursor;
			min_pos = count;
		}
		count++;
		cursor++;
	}
	return (min_pos);
}

void	sort(t_stack *stack, t_string *string)
{
	int	rot_count;
	
	while (stack->top != (stack->end + 1))
	{
		print_array(stack);
		rot_count = is_smallest_a(stack);
		while (rot_count--)
			rot_a(stack, string);
		push_b(stack, string);
	}
	while (stack->top != stack->values)
		push_a(stack, string);
}

//with the indesx sorting, i can easily find the median as well as the values above or below it :)
//explore the use of indexes and play around with this idea,
//calculate the cost of the operations and move forward in that manner
//then once you've found this strategy, rename then into pivot, and recursively split the array into smaller chunks

// I can use len - 1 and the indexes to find the median value
//once i have the median, then i can do all my operations
//depending on where the median is, then it will change the procedure
//calculate the cost of a ra move and the rra move and compare them one another. 
