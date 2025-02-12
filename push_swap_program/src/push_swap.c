/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:39 by yourlogin         #+#    #+#             */
/*   Updated: 2025/02/12 15:29:39 by yourlogin        ###   ########.ch       */
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

	parse_arguments(argc, argv, &stack);
	//printf("original array:\n");
	//print_array(&stack);
	index_convert(&stack);
	//printf("indexed array:\n");
	//print_array(&stack);
	sorting(&stack);
	//printf("sorted array\n");
	//print_array(&stack);
	return (0);
}
