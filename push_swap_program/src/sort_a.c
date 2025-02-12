/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:33:35 by yourlogin         #+#    #+#             */
/*   Updated: 2025/02/12 18:05:14 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_a(t_stack *stack, int len)
{
	int	sub_len;
	int	*pivot;
	int	pivot_i;

	if (len == 2)
	{
		if (stack->top > stack->top + 1)
			swap_a(stack);
	}
	sub_len = len / 2;
	pivot = stack->top + sub_len;
	pivot_i = pivot - stack->top;
	while (stack->top != pivot)
	{
		if (*(stack->top) > pivot_i)
			rot_a(stack);
		else
			push_b(stack);
	}
	print_array(stack);
	//sort_a(stack, len - sub_len);
	push_swap_exit(stack, "temp exit :)\n");
}
