/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:44:01 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:49:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void	print_array(t_stack *stack, char *where_i_am)
{
	int	i;

	i = 0;
	DEBUG("%s\n", where_i_am);
	while (i < stack->len)
	{
		if (&stack->values[i] == stack->top)
		{
			DEBUG("|")
		}
		else
		{
			DEBUG(" ")
		}
		DEBUG(" %d ", stack->values[i])
		i++;
	}
	DEBUG("\n\n");
}*/

int	main(int argc, char **argv)
{
	t_stack		stack;

	parse_arguments(argc, argv, &stack);
	index_convert(&stack);
	sorting(&stack);
	push_swap_exit(&stack, NULL);
	return (0);
}
