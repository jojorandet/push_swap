/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:07:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/31 17:52:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_array(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (&stack->values[i] == stack->cursor)
			printf("___\n");
		printf("%d\n", stack->values[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	parse_arguments(argc, argv, &stack);
	print_array(&stack);
	swap_a(&stack);
	printf("swap a\n\n");
	print_array(&stack);
	printf("%p cursor\n", stack.cursor);
	push_b(&stack);
	push_b(&stack);
	printf("%p cursor\n", stack.cursor);
	printf("push b\n\n");
	print_array(&stack);
	rot_a(&stack);
	printf("rot a\n\n");
	print_array(&stack);
	rot_b(&stack);
	printf("rot b\n\n");
	print_array(&stack);
	rev_rot_a(&stack);
	printf("rev_rot a\n\n");
	print_array(&stack);
	return (0);
}
