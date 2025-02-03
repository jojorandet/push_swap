/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:01:38 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/03 17:02:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# define STRING_INITIAL_LEN 64
# include "libft.h"
# include <unistd.h>

typedef struct s_string
{
	char	*values;
	int		len;
	int		total_len;
	int		is_enough_space;
}				t_string;



#endif