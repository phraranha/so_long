/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:08:52 by paranha           #+#    #+#             */
/*   Updated: 2023/11/01 12:27:42 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*convert_itoa(char *str, size_t size, unsigned int num,
					unsigned int is_negative);
static size_t	ft_intlen(int n);

char	*ft_itoa(int n)
{
	size_t			n_digits;
	unsigned int	is_negative;
	char			*str;

	n_digits = ft_intlen(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str = ft_calloc((n_digits + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	return (convert_itoa(str, n_digits, (unsigned int)n, is_negative));
}

static char	*convert_itoa(char *str, size_t size, unsigned int num,
		unsigned int is_negative)
{
	str[size] = '\0';
	while (size--)
	{
		str[size] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
