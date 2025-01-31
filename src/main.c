/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:07:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/31 11:30:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_array(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
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
	return (0);
}
