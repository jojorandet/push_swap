/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:23:25 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/27 19:39:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef	struct s_stack
{
	int *values;
	int	*cursor;
	int	len;
}		t_stack;

int		is_int(char *s);
void	check_if_int(int argc, char **argv, t_stack *stack);

void	parse_arguments(int argc, char **argv, t_stack *stack);

void	push_swap_exit(t_stack *stack, char *error);

#endif