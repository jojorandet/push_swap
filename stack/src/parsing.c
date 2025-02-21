/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/21 15:41:46 by jrandet          ###   ########.fr       */
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
	if (!check_if_sorted(stack) && !stack->error)
	{
		stack->error = 2 ;
		return ;
	}
	stack->top = (stack->values);
}

static void	init_values(t_stack *stack)
{
	stack->values = (int *)ft_calloc(stack->len, sizeof(int));
	if (!(stack->values))
	{
		stack->error = 1;
		return ;
	}
	stack->end = (stack->values + (stack->len - 1));
}

static void	parse_multiple_arg(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
		{		
			stack->error = 1;
			return ;
		}
		i++;
	}
	stack->len = (argc - 1);
	stack->len_a = stack->len;
	stack->len_b = 0;
	init_values(stack);
	fill_array((argv + 1), stack);
}

static void	parse_single_string(char *str, t_stack *stack)
{
	char	**array_string;

	array_string = ft_split(str, ' ');
	if (!array_string || !*array_string)
	{
		stack->error = 1;
		return ;
	}
	while (array_string[stack->len] != NULL)
	{
		if (!is_int(array_string[stack->len]))
		{
			stack->error = 1;
			return ;
		}
		stack->len++;
	}
	stack->len_a = stack->len;
	stack->len_b = 0;
	init_values(stack);
	fill_array(array_string, stack);
	free_list (array_string);
	array_string = NULL;
}

void	parse_arguments(int argc, char **argv, t_stack *stack)
{
	ft_bzero(stack, sizeof(t_stack));
	if (argc == 2)
		parse_single_string(argv[1], stack);
	else
		parse_multiple_arg(argc, argv, stack);
	if (stack->error == 1)
		push_swap_exit(stack, "Error!\n");
	if (stack->error == 2)
		push_swap_exit(stack, NULL);
}
