/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:06:48 by paranha           #+#    #+#             */
/*   Updated: 2024/01/19 16:49:25 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar_pf_b(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr_pf_b(char *str, size_t *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf_b(*str, len);
		str++;
	}
}

void	ft_puthexa_pf_b(unsigned long long n, char c, t_flags *flags,
		size_t *len)
{
	if (flags->hash && n != 0)
	{
		if (c == 'x')
			ft_putstr_pf_b("0x", len);
		else if (c == 'X')
			ft_putstr_pf_b("0X", len);
		flags->hash = 0;
	}
	if (n >= 16)
		ft_puthexa_pf_b(n / 16, c, flags, len);
	if (c == 'x')
		ft_putchar_pf_b(HEX_LOW_BASE[n % 16], len);
	else if (c == 'X')
		ft_putchar_pf_b(HEX_UPP_BASE[n % 16], len);
}

void	ft_putptr_pf_b(void *ptr, t_flags *flags, size_t *len)
{
	unsigned long long	ptr_address;

	if (ptr == NULL)
	{
		ft_putstr_pf_b("(nil)", len);
		return ;
	}
	else
	{
		ptr_address = (unsigned long long)ptr;
		flags->hash = 0;
		ft_putstr_pf_b("0x", len);
		ft_puthexa_pf_b(ptr_address, 'x', flags, len);
	}
}
