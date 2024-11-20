/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:05:24 by paranha           #+#    #+#             */
/*   Updated: 2024/01/19 19:19:01 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_spec(char spec)
{
	int	count;

	count = 0;
	while (SPECS[count] != '\0')
	{
		if (SPECS[count] == spec)
			return (1);
		count++;
	}
	return (0);
}

void	ft_format(va_list va, char *str, size_t *len)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), len);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), len);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), len);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(va, int), len);
	else if (*str == 'u')
		ft_putuint_pf(va_arg(va, unsigned int), len);
	else if (*str == 'x' || *str == 'X')
		ft_puthexa_pf(va_arg(va, unsigned int), *str, len);
	else if (*str == '%')
		ft_putchar_pf(*str, len);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	len;

	if (!str)
		return (-1);
	len = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (!ft_is_spec(*str))
				str++;
			ft_format(va, (char *)str, &len);
		}
		else
			ft_putchar_pf(*str, &len);
		str++;
	}
	va_end(va);
	return (len);
}
