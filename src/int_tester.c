/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:37:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/30 15:39:48 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			{
				push_swap_exit(stack, "double found!\n");
				return ;
			}
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
	while (argv[i] && i < argc)
	{
		if (!is_int(argv[i]))
			push_swap_exit(stack, "argument is not an int\n");
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
