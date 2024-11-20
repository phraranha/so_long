/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:17:02 by paranha           #+#    #+#             */
/*   Updated: 2023/11/01 11:08:15 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strnlen(dest, size);
	slen = ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	return (dlen + ft_strlcpy(dest + dlen, src, size - dlen));
}

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen)
	{
		if (!*s)
			break ;
		len++;
		s++;
	}
	return (len);
}
