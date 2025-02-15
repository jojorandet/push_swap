/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:35:24 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/15 19:28:42 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void	sort(t_stack *stack, int len, int pivot_value, int *pushed_count, int *operations )

void	sort_a(t_stack *stack, int len)
{
	int	sub_len;
	int	pivot_value;
	int	pushed_count;
	int	operations;
	
	if (len <= 1)
		return;
	if (len == 2)
	{
		if (*(stack->top) > *(stack->top + 1))
			swap_a(stack);
		return ;
	}
	sub_len = len / 2;
	pivot_value = *(stack->top + sub_len);
	pushed_count = 0;
	operations = 0;

	while ((pushed_count < sub_len) && (operations < len))
	{
		if (*(stack->top) < pivot_value)
		{
			push_b(stack);
			pushed_count++;
		}
		else
		{
			rot_a(stack);
		}
		operations++;
	}
	while (operations > len - pushed_count)
	{
		rev_rot_a(stack);
		operations--;
	}
	sort_a(stack, len - sub_len);
	sort_b(stack, len);
}
