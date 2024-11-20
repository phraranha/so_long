/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:11:36 by paranha           #+#    #+#             */
/*   Updated: 2023/11/08 15:05:37 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = ft_strlen(start);
	while (end && ft_strchr(set, start[end]))
		end--;
	str = ft_substr(start, 0, end + 1);
	return (str);
}
