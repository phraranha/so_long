/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:05:11 by paranha           #+#    #+#             */
/*   Updated: 2024/01/19 16:57:45 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"
# define DECIMAL_BASE "0123456789"
# define SPECS "%cspiduxX+# "

enum	e_specifiers
{
	PERCENT = '%',
	CHARACTER = 'c',
	STRING = 's',
	POINTER = 'p',
	INTEGER = 'i',
	DECIMAL = 'd',
	UNSIGNED = 'u',
	HEX_LOWER = 'x',
	HEX_UPPER = 'X'
};

typedef struct s_flags
{
	int	plus;
	int	hash;
	int	space;
}		t_flags;

int		ft_printf(char const *str, ...);

void	ft_putchar_pf_b(char c, size_t *len);
void	ft_putstr_pf_b(char *str, size_t *len);
void	ft_putnbr_pf_b(int num, t_flags *flags, size_t *len);
void	ft_putuint_pf_b(unsigned int num, size_t *len);
void	ft_puthexa_pf_b(unsigned long long n, char c, t_flags *flags,
			size_t *len);
void	ft_putptr_pf_b(void *ptr, t_flags *flags, size_t *len);

#endif
