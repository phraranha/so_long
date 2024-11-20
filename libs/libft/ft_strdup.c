/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:24:03 by paranha           #+#    #+#             */
/*   Updated: 2023/11/07 17:03:20 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*n;
	int		size;

	size = 0;
	while (s[size])
		size++;
	n = (char *)ft_calloc((size + 1), sizeof(char));
	if (!n)
		return (NULL);
	ft_memmove(n, s, size + 1);
	return (n);
}
