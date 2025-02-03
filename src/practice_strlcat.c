/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice_strlcat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:25:11 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/03 16:00:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	my_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	remaining_space;
	char	*s;
	char	*d;
		
	if (!src)
		return (1);
	if (dstsize == 0)
		return ft_strlen(src);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (src_len + dst_len); //if there was unlimiterd space this is how much i would have appended
	remaining_space = dstsize - dst_len - 1;
	s = (char *)src;
	d = dst + dst_len;
	while (*s && remaining_space)
	{
		*d++ = *s++;
		remaining_space--;
	}
	*d = '\0';
	return (dst_len +src_len);
}


//garantees null temination if there is space, meaning the dest can be bigger than dstsize

//strlcat returne the total lenth of the string that would have been created if there was 
//unlimited space


//if the dstsize is 0, then i cannot copy it. so i return the src len saying hey i need that much space
//if the dst size is smaller than the the dstlen, then it means there
//is not enough space to copy it. this means i will return the length of the source
//so that i know the proper dest size i need to send 
//i need to return the amount of space needed 