/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:06:48 by paranha           #+#    #+#             */
/*   Updated: 2024/01/19 16:51:11 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr_pf(char *str, size_t *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf(*str, len);
		str++;
	}
}

void	ft_puthexa_pf(unsigned long long n, char c, size_t *len)
{
	if (n >= 16)
		ft_puthexa_pf(n / 16, c, len);
	if (c == 'x')
		ft_putchar_pf(HEX_LOW_BASE[n % 16], len);
	else if (c == 'X')
		ft_putchar_pf(HEX_UPP_BASE[n % 16], len);
}

void	ft_putptr_pf(void *ptr, size_t *len)
{
	unsigned long long	ptr_address;

	if (ptr == NULL)
		ft_putstr_pf("(nil)", len);
	else
	{
		ptr_address = (unsigned long long)ptr;
		ft_putstr_pf("0x", len);
		ft_puthexa_pf(ptr_address, 'x', len);
	}
}
