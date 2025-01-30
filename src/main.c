/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:07:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/30 14:18:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		i;

	i = 0;
	parse_arguments(argc, argv, &stack); // done using argc argv, now i can move on
	while (i < stack.len)
	{
		printf("%d\n", stack.values[i]);
		i++;
	}
	check_doubles(&stack);
	return (0);
}
