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

int		fmt_x(t_param *p)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(p->va, int);
	if (p->flags[NODIGIT] && x == 0)
		return (print_spaces(p));
	ln = (p->precision > len_uint(x, 16)) ? p->precision : len_uint(x, 16)
		+ 2 * (p->flags[HASH] && x != 0);
	if (p->flags[LEFT])
		ret += print_x(x, p);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > ln && ret++)
			pchar('0');
	while (!p->flags[ZPAD] && p->padding-- > ln && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_x(x, p);
	return (ret);
}

int		fmt_bx(t_param *p)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(p->va, int);
	if (p->flags[NODIGIT] && x == 0)
		return (print_spaces(p));
	ln = (p->precision > len_uint(x, 16)) ? p->precision : len_uint(x, 16)
		+ 2 * (p->flags[HASH] && x != 0);
	if (p->flags[LEFT])
		ret += print_bx(x, p);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > ln && ret++)
			pchar('0');
	while (!p->flags[ZPAD] && p->padding-- > ln && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_bx(x, p);
	return (ret);
}

int		fmt_b(t_param *p)
{
	int		ret;
	int		b;

	ret = 0;
	b = va_arg(p->va, int);
	if (p->flags[NODIGIT] && b == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		pnbr_base(b, 2);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > len_int(b, 2) && ret++)
			pchar('0');
	while (!p->flags[ZPAD] && p->padding-- > len_int(b, 2) && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		pnbr_base(b, 2);
	ret += len_int(b, 2);
	return (ret);
}

int		fmt_d(t_param *p)
{
	int		d;
	int		ret;

	ret = 0;
	d = va_arg(p->va, int);
	if (p->flags[NODIGIT] && d == 0)
		return (0);
	if (p->flags[LEFT])
		ret += print_d(d, p);
	if ((!p->flags[ZPAD] || p->flags[LEFT] || p->precision) && p->padding)
		while (p->padding-- > (p->flags[PLUS] || p->flags[SPACE])
				+ (d < 0 && p->precision > len_int(ABS(d), 10)) +
				(p->precision > len_int(d, 10) ? p->precision :
				len_int(d, 10)) && ret++)
			pchar(32);
	if (!p->flags[LEFT])
		ret += print_d(d, p);
	return (ret);
}

int		fmt_bd(t_param *p)
{
	int		ret;
	long	bd;

	ret = 0;
	bd = va_arg(p->va, long);
	if (p->flags[NODIGIT] && bd == 0)
		return (0);
	if (p->flags[LEFT])
		ret += print_bd(bd, p);
	if (!p->flags[ZPAD] && p->padding)
		while (p->padding-- > (p->flags[PLUS] || p->flags[SPACE])
				+ (bd < 0 && p->precision > len_long(bd, 10))
				+ (p->precision > len_long(bd, 10) ?
					p->precision : len_long(bd, 10))
				&& ret++)
			pchar(32);
	if (!p->flags[LEFT])
		ret += print_bd(bd, p);
	return (ret);
}