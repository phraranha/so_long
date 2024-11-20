/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:06:48 by paranha           #+#    #+#             */
/*   Updated: 2024/01/19 16:49:50 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putsign_pf_b(int n, t_flags *flags, size_t *len)
{
	if (flags->plus && n >= 0)
	{
		ft_putchar_pf_b('+', len);
		flags->plus = 0;
	}
	else if (flags->space && n >= 0)
	{
		ft_putchar_pf_b(' ', len);
		flags->space = 0;
	}
	else if (n < 0)
	{
		ft_putchar_pf_b('-', len);
	}
}

void	ft_putnbr_pf_b(int num, t_flags *flags, size_t *len)
{
	long	nbr;

	nbr = (long)num;
	ft_putsign_pf_b(num, flags, len);
	if (nbr < 0)
		nbr *= -1;
	flags->plus = 0;
	flags->space = 0;
	if (nbr < 10)
		ft_putchar_pf_b((nbr + '0'), len);
	else
	{
		ft_putnbr_pf_b((nbr / 10), flags, len);
		ft_putnbr_pf_b((nbr % 10), flags, len);
	}
}

void	ft_putuint_pf_b(unsigned int num, size_t *len)
{
	if (num >= 10)
		ft_putuint_pf_b(num / 10, len);
	ft_putchar_pf_b(DECIMAL_BASE[num % 10], len);
}
