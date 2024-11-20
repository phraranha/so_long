/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:10:56 by paranha           #+#    #+#             */
/*   Updated: 2023/11/07 17:07:22 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;
	char	*str;

	i = 0;
	str = (char *)s;
	character = (char)c;
	while (str[i])
	{
		if (str[i] == character)
			return (&str[i]);
		i++;
	}
	if (character == '\0')
		return (&str[i]);
	return (NULL);
}
