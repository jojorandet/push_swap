/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/02 17:45:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_elements(t_stack *stack)
{
	int	*values;

	values = stack->values;
	push_b(stack);
	push_b(stack);
	sort_three_elements(stack);
	
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
	int i;
	
	i = 0;
	if (stack->values[i] > stack->values[i + 1])
		swap_a(stack);
}

void	sorting(t_stack *stack)
{
	if (stack->len == 2)
		sort_two_elements(stack);
	if (stack->len == 3)
		sort_three_elements(stack);
	/*if (stack->len == 5)
		sort_five_elements(stack);
	else
		sort(stack);*/
	return ;
}