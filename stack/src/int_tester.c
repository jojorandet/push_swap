/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:37:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/12 10:34:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

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

void	check_array_len(t_stack *stack, char **array_of_strings)
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
