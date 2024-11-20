/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:05:11 by paranha           #+#    #+#             */
/*   Updated: 2024/01/19 19:18:15 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"
# define DECIMAL_BASE "0123456789"  
# define SPECS "%cspiduxX"

int		ft_printf(char const *str, ...);

void	ft_putchar_pf(char c, size_t *len);
void	ft_putstr_pf(char *str, size_t *len);
void	ft_putnbr_pf(int num, size_t *len);
void	ft_putuint_pf(unsigned int num, size_t *len);
void	ft_puthexa_pf(unsigned long long n, char c, size_t *len);
void	ft_putptr_pf(void *ptr, size_t *len);

#endif
