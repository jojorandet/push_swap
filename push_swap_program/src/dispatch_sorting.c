/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:06:32 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:45:58 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting(t_stack *stack)
{
	if (stack->len == 2)
		sort_two_elements(stack);
	else if (stack->len == 3)
		sort_three_elements(stack);
	else if (stack->len == 5)
		sort_five_elements(stack);
	else
		sort_a(stack, stack->len);
	return ;
}
