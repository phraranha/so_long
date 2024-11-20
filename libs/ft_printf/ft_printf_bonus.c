/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:23:27 by paranha           #+#    #+#             */
/*   Updated: 2024/01/19 16:48:31 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_is_spec_b(char spec)
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

void	ft_parse_flags_b(const char **str, t_flags *flags)
{
	while (**str == '+' || **str == '#' || **str == ' ')
	{
		if (**str == '+')
			flags->plus = 1;
		else if (**str == '#')
			flags->hash = 1;
		else if (**str == ' ')
			flags->space = 1;
		(*str)++;
	}
}

void	ft_format_b(va_list va, const char **str, size_t *len)
{
	t_flags	flags;

	flags.plus = 0;
	flags.hash = 0;
	flags.space = 0;
	ft_parse_flags_b(str, &flags);
	if (**str == HEX_LOWER || **str == HEX_UPPER)
		ft_puthexa_pf_b(va_arg(va, unsigned int), **str, &flags, len);
	if (**str == CHARACTER)
		ft_putchar_pf_b(va_arg(va, int), len);
	else if (**str == STRING)
		ft_putstr_pf_b(va_arg(va, char *), len);
	else if (**str == POINTER)
		ft_putptr_pf_b(va_arg(va, void *), &flags, len);
	else if (**str == INTEGER || **str == DECIMAL)
		ft_putnbr_pf_b(va_arg(va, int), &flags, len);
	if (**str == UNSIGNED)
		ft_putuint_pf_b(va_arg(va, unsigned int), len);
	else if (**str == PERCENT)
		ft_putchar_pf_b(**str, len);
}

int	ft_printf(const char *str, ...)
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
			while (!ft_is_spec_b(*str))
				str++;
			ft_format_b(va, &str, &len);
		}
		else
			ft_putchar_pf_b(*str, &len);
		str++;
	}
	va_end(va);
	return (len);
}
