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

void	pulong_base_up(unsigned long n, unsigned long base)
{
	if (n >= base)
		pulong_base_up(n / base, base);
	pchar(base_ucase[n % base]);
}

void	pull_base(unsigned long long n, unsigned long long base)
{
	if (n >= base)
		pull_base(n / base, base);
	pchar(base_lcase[n % base]);
}

void	pll_base(long long n, long long base)
{
	if (base == 10 && n < 0)
	{
		pchar('-');
		if (n == LLONG_MIN && (n /= 10))
			pchar('9');
		n = -n;
	}
	if (n >= base)
		pll_base(n / base, base);
	pchar(base_lcase[n % base]);
}

void	pull_base_up(unsigned long long n, unsigned long long base)
{
	if (n >= base)
		pull_base_up(n / base, base);
	pchar(base_ucase[n % base]);
}

void	puint_base_up(unsigned int n, unsigned int base)
{
	if (n >= base)
		puint_base_up(n / base, base);
	pchar(base_ucase[n % base]);
}
