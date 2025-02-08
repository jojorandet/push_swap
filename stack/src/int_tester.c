/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:37:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/08 22:19:47 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	check_int_max_min(t_stack *stack, char **array_of_strings)
{
	int	i;

	i = 0;
	while (array_of_strings[i])
	{
		if (array_of_strings[i][0] == '-')
		{
			if (ft_strlen(array_of_strings[i]) > 11)
				push_swap_exit(stack, "Input error: input too long!\n");
		}
		else
		{
			if (ft_strlen(array_of_strings[i]) > 10)
				push_swap_exit(stack, "Input error: input too long\n");
		}
		i++;
	}
}

void	check_doubles(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack && stack->values && (i < stack->len))
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->values[i] == stack->values[j])
				push_swap_exit(stack, "Input Error: a double is found in input.\n");
			j++;
		}
		i++;
	}
	return ;
}

void	check_if_int(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	printf("input received: %s\n", argv[1]);
	printf("First arg characters: \n");
	for(int j = 0; argv[1][j]; j++)
	{
		printf("%c (%d) \n", argv[1][j], argv[1][j]);
	}
	printf("\n");
	while (argv[i] && i < argc)
	{
		if (!is_int(argv[i]))
			push_swap_exit(stack, "Input Error: argument is not int.\n");
		i++;
	}
}

int	is_int(char *s)
{
	if (!s)
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!(ft_isdigit(*s)))
			return (0);
		s++;
	}
	return (1);
}
