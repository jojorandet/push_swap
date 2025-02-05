/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:34:47 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/05 10:54:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/string_utils.h"

void	free_string(t_string *string)
{
	if (!string || !string->values)
		return ;
	free (string->values);
	string->values = NULL;
}

void	init_string(t_string *string)
{
	string->values = ft_calloc(STRING_INITIAL_LEN, 1);
	if (!string->values)
		return ;
	string->total_len = STRING_INITIAL_LEN;
}

static int is_enough_space(t_string *string)
{
	char	*new;
	
	if (!string->values)
		init_string(string);
	if (string->len > (string->total_len / 4))
	{
		new = ft_calloc(string->total_len * 2, 1);
		if (!new)
		{
			free_string(string);
			return (1);
		}
		ft_memmove(new, string->values, string->total_len);
		free(string->values);
		string->values = new;
		string->total_len *= 2;
		return (0);
	}
	return (0);
}

void	append_result_string(t_string *string, char c)
{
	if (is_enough_space(string))
		return ;
	string->values[string->len++] = c;
	string->values[string->len] = '\0';
}
