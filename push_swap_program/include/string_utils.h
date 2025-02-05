/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:01:38 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/05 13:00:44 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H
# define STRING_INITIAL_LEN 4
# include "../../libft/libft.h"
# include <unistd.h>

typedef struct s_string
{
	char	*values;
	int		len;
	int		total_len;
	int		is_enough_space;
}				t_string;

void	append_result_string(t_string *string, char c);

#endif