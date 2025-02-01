/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:07:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/01 19:51:57 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_array(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (&stack->values[i] == stack->top)
			printf(" | ");
		printf(" %d ", stack->values[i]);
		i++;
	}
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	parse_arguments(argc, argv, &stack);
	print_array(&stack);
	index_convert(&stack);
	return (0);
}
