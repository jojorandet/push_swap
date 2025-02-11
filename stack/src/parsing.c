/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/10 15:12:15 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

static void	fill_array(char **array_string, t_stack *stack)
{
	int	*value;

	check_array_len(stack, array_string);
	value = stack->values;
	while (value <= stack->end)
		*(value++) = atoll_push_swap(stack, *(array_string++));
	check_doubles(stack);
	stack->top = (stack->values);
}

static void	init_values(t_stack *stack)
{
	stack->values = (int *)ft_calloc(stack->len, sizeof(int)); //i used to do a check if(!stack) but since stack is never malloced, it cannot be NULL.
	if (!stack->values)
		push_swap_exit(stack, "Memory error: Memory alloc failed for stack->values.\n");
	stack->end = (stack->values + (stack->len - 1));
}

static void	parse_multiple_arg(int argc, char **argv, t_stack *stack)
{
	check_if_int(argc, argv, stack);
	stack->len = (argc - 1);
	stack->len_a = stack->len;
	stack->len_b = 0;
	init_values(stack);
	fill_array((argv + 1), stack);
}

static void	parse_single_string(int argc, char **argv, t_stack *stack)
{
	char	**array_string;

	array_string = ft_split(argv[1], ' ');
	if (!array_string || !*array_string)
		push_swap_exit(stack, "Parsing Error: ft_split has failed\n");
	check_if_int(argc, array_string, stack);
	while (array_string[stack->len] != NULL)
		stack->len++;
	stack->len_a = stack->len;
	stack->len_b = 0;
	init_values(stack);
	fill_array(array_string, stack);
	free (array_string);
	array_string = NULL;
}

void	parse_arguments(int argc, char **argv, t_stack *stack)
{
	ft_bzero(stack, sizeof(t_stack));
	if (argc == 2)
		parse_single_string(argc, argv, stack);
	else
		parse_multiple_arg(argc, argv, stack);
}
