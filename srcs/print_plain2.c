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

int		print_u(unsigned int d, t_param *p)
{
	int		ret;

	ret = 0;
	while (p->precision-- > len_uint(d, 10) && ret++)
		pchar('0');
	puint_base(d, 10);
	ret += len_uint(d, 10);
	return (ret);
}

int		print_bu(unsigned long d, t_param *p)
{
	int		ret;

	ret = 0;
	while (p->precision-- > len_ulong(d, 10) && ret++)
		pchar('0');
	pulong_base(d, 10);
	ret += len_ulong(d, 10);
	return (ret);
}

int		print_p(long hex, t_param *p)
{
	int		ret;

	ret = 0;
	pstr("0x");
	if (p->flags[NODIGIT] && hex == 0)
		return (2);
	if (p->precision && hex == 0)
		while (p->precision-- > 1 && ret++)
			pchar('0');
	plong_base(hex, 16);
	ret += 2 + len_long(hex, 16);
	return (ret);
}

int		print_x(unsigned int x, t_param *p)
{
	int		ret;
	int		b;

	b = (x != 0) && p->flags[HASH];
	if (b)
		pstr("0x");
	ret = 2 * b;
	while (p->precision-- > len_uint(x, 16) && ret++)
		pchar('0');
	puint_base(x, 16);
	ret += len_uint(x, 16);
	return (ret);
}

int		print_bx(unsigned int x, t_param *p)
{
	int		ret;
	int		b;

	b = (x != 0) && p->flags[HASH];
	if (b)
		pstr("0X");
	ret = 2 * b;
	while (p->precision-- > len_uint(x, 16) && ret++)
		pchar('0');
	puint_base_ucase(x, 16);
	ret += len_uint(x, 16);
	return (ret);
}
