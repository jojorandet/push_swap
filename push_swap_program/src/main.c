/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:07:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/07 16:31:20 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_array(t_stack *stack)
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
	t_stack		stack;
	t_string	string;

	parse_arguments(argc, argv, &stack);
	printf("original array:\n");
	print_array(&stack);
	index_convert(&stack);
	printf("indexed array:\n");
	print_array(&stack);
	sorting(&stack, &string);
	return (0);
}
