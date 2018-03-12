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

int		print_ld(long d, t_param *p)
{
	int		ret;
	int		ici;
	int		q;

	q = 0;
	ici = 0;
	ret = 0;
	if ((p->flags[PLUS] || p->flags[SPACE]) && d >= 0)
	{
		ici = 1;
		pchar (p->flags[PLUS] ? '+' : 32)
		(ret)++;
	}
	if (d < 0)
	{
		ici = 1;
		q = d == LONG_MIN ? 1 : 0;
		if (!q)
			pchar('-');
		ret++;
		d = -d;
	}
	if (p->flags[ZPAD] && !p->precision && !p->flags[LEFT])
		while (p->padding-- > len_long(d, 10) + ici && ret++)
			pchar('0');
	while (p->precision-- > len_long(d, 10) && ret++)
		pchar('0');
	plong_base(d, 10);
	ret += len_long(d, 10) - q;
	return (ret);
}

int		print_lo(unsigned long d, t_param *p)
{
	int		ret;
	int		b;

	b = (d != 0) && p->flags[HASH] && (p->precision <= len_ulong(d, 8));
	if (b)
		pchar('0');
	ret = b;
	while (p->precision-- > b + len_ulong(d, 8) && ret++)
		pchar('0');
	pulong_base(d, 8);
	ret += len_ulong(d, 8);
	return (ret);
}

int		print_lu(unsigned long d, t_param *p)
{
	int		ret;

	ret = 0;
	while (p->precision-- > len_ulong(d, 10) && ret++)
		pchar('0');
	pulong_base(d, 10);
	ret += len_ulong(d, 10);
	return (ret);
}

int		print_lx(unsigned long x, t_param *p)
{
	int		ret;
	int		b;

	b = (x != 0) && p->flags[HASH];
	if (b)
		pstr("0x");
	ret = 2 * b;
	while (p->precision-- > len_ulong(x, 16) && ret++)
		pchar('0');
	pulong_base(x, 16);
	ret += len_ulong(x, 16);
	return (ret);
}

int		print_lbx(unsigned long x, t_param *p)
{
	int		ret;
	int		b;

	b = (x != 0) && p->flags[HASH];
	if (b)
		pstr("0X");
	ret = 2 * b;
	while (p->precision-- > len_ulong(x, 16) && ret++)
		pchar('0');
	pulong_base_up(x, 16);
	ret += len_ulong(x, 16);
	return (ret);
}
