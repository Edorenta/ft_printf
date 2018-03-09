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

int		print_u(unsigned int d, int *flags)
{
	int		ret;

	ret = 0;
	while (flags[12]-- > len_uint(d, 10) && ret++ > -1)
		pchar('0');
	puint_base(d, 10);
	ret += len_uint(d, 10);
	return (ret);
}

int		print_bu(unsigned long d, int *flags)
{
	int		ret;

	ret = 0;
	while (flags[12]-- > len_ulong(d, 10) && ret++ > -1)
		pchar('0');
	pulong_base(d, 10);
	ret += len_ulong(d, 10);
	return (ret);
}

int		print_p(long p, int *flags)
{
	int		ret;

	ret = 0;
	pstr("0x");
	if (flags[13] && p == 0)
		return (2);
	if (flags[12] && p == 0)
		while (flags[12]-- > 1 && ret++ > -1)
			pchar('0');
	plong_base(p, 16);
	ret += 2 + len_long(p, 16);
	return (ret);
}

int		print_x(unsigned int x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		pstr("0x");
	ret = 2 * b;
	while (flags[12]-- > len_uint(x, 16) && ret++ > -1)
		pchar('0');
	puint_base(x, 16);
	ret += len_uint(x, 16);
	return (ret);
}

int		print_bx(unsigned int x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		pstr("0X");
	ret = 2 * b;
	while (flags[12]-- > len_uint(x, 16) && ret++ > -1)
		pchar('0');
	puint_base_up(x, 16);
	ret += len_uint(x, 16);
	return (ret);
}
