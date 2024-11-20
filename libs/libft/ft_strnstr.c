/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:11:29 by paranha           #+#    #+#             */
/*   Updated: 2023/10/25 18:54:24 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	if (!big && !len)
		return (NULL);
	while (*big && len--)
	{
		i = 0;
		while (little[i] && big[i] == little[i] && i <= len)
		{
			if (!little[i + 1])
				return ((char *)big);
			i++;
		}
		big++;
	}
	return (NULL);
}
