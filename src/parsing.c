/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/30 12:43:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(char **array_string, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		stack->values[i] = ft_atoi(array_string[i]);
		i++;
	}
}

static void	init_values(t_stack *stack)
{
	if (!stack)
		return ;
	stack->values = (int *)ft_calloc(stack->len, sizeof(int)); //ft caloc does theft bzero inside just for the vakues array
	if (!stack->values)
		push_swap_exit(stack, "stack->values is NULL\n");
}

static void	parse_multiple_arg(int argc, char **argv, t_stack *stack)
{
	check_if_int(argc, argv, stack);
	stack->len = (argc - 1);
	init_values(stack);
	fill_array((argv + 1), stack);
}

static void	parse_single_string(int argc, char **argv, t_stack *stack)
{
	char	**array_string;

	array_string = ft_split(argv[1], ' '); // mnalloc is done in the spli
	if (!array_string)
	{
		free(array_string);
		array_string = NULL;
		push_swap_exit(stack, "split failed, array_string NULL!\n");
	}
	check_if_int(argc, array_string, stack);
	while (array_string[stack->len] != NULL) // i do this because i do not have a null terminatir and need to go to the end 
		stack->len++; // first 0, then 1 , 2, 3 , and the 4th is NULL stop (case of 3 4 5 6 NULL)
	init_values(stack);
	fill_array(array_string, stack);
	free (array_string);
	array_string = NULL;
}

void	parse_arguments(int argc, char **argv, t_stack *stack)
{
	
	ft_bzero(stack, sizeof(t_stack));
	if (argc < 2)
		push_swap_exit(stack, "arguments incomplete!\n");
	if (argc == 2)
		parse_single_string(argc, argv, stack);
	else 
		parse_multiple_arg(argc, argv, stack);
}


