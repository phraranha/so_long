/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:06:48 by paranha           #+#    #+#             */
/*   Updated: 2024/01/18 15:44:35 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int num, size_t *len)
{
	long	nbr;

	nbr = (long)num;
	if (nbr < 0)
	{
		ft_putchar_pf('-', len);
		nbr = -nbr;
	}
	if (nbr < 10)
		ft_putchar_pf((nbr + '0'), len);
	if (nbr > 9)
	{
		ft_putnbr_pf((nbr / 10), len);
		ft_putnbr_pf((nbr % 10), len);
	}
}

void	ft_putuint_pf(unsigned int num, size_t *len)
{
	if (num >= 10)
		ft_putuint_pf(num / 10, len);
	ft_putchar_pf(DECIMAL_BASE[num % 10], len);
}
