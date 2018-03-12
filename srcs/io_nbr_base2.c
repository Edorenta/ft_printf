/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:36:17 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/09 12:46:24 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	pulong_base_ucase(unsigned long n, uint8_t base)
{
	if (n >= base)
		pulong_base_ucase(n / base, base);
	pchar(BASE_UCASE[n % base]);
}

void	pull_base(unsigned long long n, uint8_t base)
{
	if (n >= base)
		pull_base(n / base, base);
	pchar(BASE_LCASE[n % base]);
}

void	pll_base(long long n, uint8_t base)
{
	if (base == 10 && n < 0)
		pchar('-');
	if ((n = (n < 0 ? -n : n)) >= base)
		pll_base(n / base, base);
	pchar(BASE_LCASE[n % base]);
}

void	pull_base_ucase(unsigned long long n, uint8_t base)
{
	if (n >= base)
		pull_base_ucase(n / base, base);
	pchar(BASE_UCASE[n % base]);
}

void	puint_base_ucase(unsigned int n, uint8_t base)
{
	if (n >= base)
		puint_base_ucase(n / base, base);
	pchar(BASE_UCASE[n % base]);
}
