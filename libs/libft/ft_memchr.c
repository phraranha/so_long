/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:50:56 by paranha           #+#    #+#             */
/*   Updated: 2023/10/10 18:45:17 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*start;
	unsigned char	character;

	i = 0;
	start = (unsigned char *)s;
	character = (unsigned char)c;
	while (i < n)
	{
		if (start[i] == character)
			return (&start[i]);
		i++;
	}
	return (NULL);
}
