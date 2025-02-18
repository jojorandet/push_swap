/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:06:46 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:47:12 by jrandet          ###   ########.fr       */
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
	if (stack->len_b)
		push_a(stack);
	print_array(stack, "in sort_five_elements - sort_small_n.c\n");
	push_swap_exit(stack, NULL);
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
	push_swap_exit(stack, NULL);
}
