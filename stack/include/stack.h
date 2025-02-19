/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:27:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:56:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../../libft/libft.h"
# include "../../push_swap_program/include/push_swap.h"

typedef struct s_stack
{
	int	*values;
	int	*top;
	int	*end;
	int	top_i;
	int	len;
	int	len_a;
	int	len_b;
}				t_stack;

void	free_stack(t_stack *stack);

void	parse_arguments(int argc, char **argv, t_stack *stack);
void	check_if_int(int argc, char **argv, t_stack *stack);
int		is_int(char *s);
void	check_array_len(t_stack *stack, char **array_of_strings);
int		atoll_push_swap(t_stack *stack, const char *str);
void	check_doubles(t_stack *stack);

#endif