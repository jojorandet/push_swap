/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/07 12:46:50 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void	sort_five_elements(t_stack *stack, t_string *string)
{
	int	*values;

	values = stack->values;
	push_b(stack, string);
	push_b(stack, string);
	sort_three_elements(stack, string);
	
}*/

void	sort_three_elements(t_stack *stack, t_string *string)
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
		swap_a(stack, string);
	if ((*top > *middle) && (*middle > *bottom) && (*bottom < *top))
	{
		swap_a(stack, string);
		rev_rot_a(stack, string);
	}
	if ((*top > *middle) && (*middle < *bottom) && (*bottom > *middle))
		rot_a(stack, string);
	if ((*top < *middle) && (*middle > *bottom) && (*bottom > *top))
	{
		swap_a(stack, string);
		rot_a(stack, string);
	}
	if ((*top < *middle) && (*middle > *bottom) && (*bottom < *top))
		rev_rot_a(stack, string);
}

void	sort_two_elements(t_stack *stack, t_string *string)
{
	int i;
	
	i = 0;
	if (stack->values[i] > stack->values[i + 1])
		swap_a(stack, string);
}

void	sorting(t_stack *stack, t_string *string)
{
	if (stack->len == 2)
		sort_two_elements(stack, string);
	if (stack->len == 3)
		sort_three_elements(stack, string);
	/*if (stack->len == 5)
		sort_five_elements(stack);*/
	else
		prepare_sort(stack, string);
	return ;
}