/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:56:02 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/03 16:19:12 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	len_dst;
	size_t	remaining_buffer;

	if (!src)
		return (1);
	len_dst = ft_strlen(dst);
	s = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= len_dst)
		return (len_dst + ft_strlen(src));
	d = dst + len_dst;
	remaining_buffer = dstsize - len_dst - 1;
	while (*s && remaining_buffer--)
		*d++ = *s++;
	*d = '\0';
	return (len_dst + ft_strlen(src));
}
