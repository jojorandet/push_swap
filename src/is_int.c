/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:37:21 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/27 19:14:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
