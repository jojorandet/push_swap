/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:27:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/21 15:38:22 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
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
	int	error;
}				t_stack;

void	free_stack(t_stack *stack);

void	parse_arguments(int argc, char **argv, t_stack *stack);
void	check_if_int(int argc, char **argv, t_stack *stack);
int		is_int(char *s);
void	check_array_len(t_stack *stack, char **array_of_strings);
int		atoll_push_swap(t_stack *stack, const char *str);
void	check_doubles(t_stack *stack);
int		check_if_sorted(t_stack *stack);
void	free_list(char **list);

#endif