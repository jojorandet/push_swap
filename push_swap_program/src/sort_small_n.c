/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 20:40:58 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_five_elements(t_stack *stack)
{
	push_index_to_b(stack, 0);
	if (stack->len_a > 3)
		push_index_to_b(stack, 1);
	sort_three_elements(stack);
	push_a(stack);
	if (stack->len_b) //after pushing a check if this worked 
		push_a(stack);
	print_array(stack);
	push_swap_exit(stack, "temp exit :)\n");
}

void	sort_three_elements(t_stack *stack)
{
	int	*top;
	int	*middle;
	int	*bottom;

	top = stack->top;
	middle = top + 1;
	bottom = stack->end;
	if ((*top < *middle) && (*middle < *bottom))
		return ;
	if ((*top < *middle) && (*middle > *bottom) && (*top > *bottom))
		swap_a(stack);
	if ((*top > *middle) && (*middle > *bottom) && (*bottom < *top))
	{
		swap_a(stack);
		rev_rot_a(stack);
	}
	if ((*top > *middle) && (*middle < *bottom) && (*bottom > *middle))
		rot_a(stack);
	if ((*top < *middle) && (*middle > *bottom) && (*bottom > *top))
	{
		swap_a(stack);
		rot_a(stack);
	}
	if ((*top < *middle) && (*middle > *bottom) && (*bottom < *top))
		rev_rot_a(stack);
}

void	sort_two_elements(t_stack *stack)
{
	if (stack->values[0] != 0)
		swap_a(stack);
}
