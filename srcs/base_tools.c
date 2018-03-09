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

void	pnbr_base(int n, int b)
{
	if (n >= b)
		pnbr_base(n / b, b);
	pchar(base_lcase[n % b]);
}

void	pnbr_base_ucase(int n, int b)
{
	if (n >= b)
		pnbr_base_ucase(n / b, b);
	pchar(base_ucase[n % b]);
}

void	plong_base(long n, long b)
{
	if (b == 10 && n < 0)
	{
		pchar('-');
		if (n == LONG_MIN && (n /= 10))
			pchar('9');
		n = -n;
	}
	if (n >= b)
		plong_base(n / b, b);
	pchar(base_lcase[n % b]);
}

void	pulong_base(unsigned long n, unsigned long b)
{
	if (n >= b)
		pulong_base(n / b, b);
	pchar(base_lcase[n % b]);
}

void	puint_base(unsigned int n, unsigned int b)
{
	if (n >= b)
		puint_base(n / b, b);
	pchar(base_lcase[n % b]);
}
