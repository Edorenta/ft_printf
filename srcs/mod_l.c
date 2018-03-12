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

int		fmt_ld(t_param *p)
{
	long	d;
	int		ret;

	ret = 0;
	d = va_arg(p->va, long);
	if (!(p->precision) && d == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_ld(d, p);
	if ((!p->flags[ZPAD] || p->flags[LEFT] || p->precision) && p->padding)
		while (p->padding-- > (p->flags[PLUS] || p->flags[SPACE])
				+ (d < 0 && p->precision > len_long(ABS(d), 10)) +
				(p->precision > len_long(d, 10) ? p->precision :
				len_long(d, 10)) && ret++)
			pchar(32);
	if (!p->flags[LEFT])
		ret += print_ld(d, p);
	return (ret);
}

int		fmt_lo(t_param *p)
{
	unsigned long	o;
	int				ret;

	ret = 0;
	o = va_arg(p->va, unsigned long);
	if (!(p->precision) && o == 0 && !p->flags[HASH])
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_lo(o, p);
	if (p->flags[ZPAD] && !p->precision && !p->flags[LEFT])
		while (p->padding-- > len_ulong(o, 8) && ret++)
			pchar('0');
	while (p->padding-- > (p->flags[HASH] && o != 0) +
			(p->precision > len_ulong(o, 8) ? p->precision :
			len_ulong(o, 8)) && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_lo(o, p);
	return (ret);
}

int		fmt_lu(t_param *p)
{
	unsigned long	u;
	int				ret;

	ret = 0;
	u = va_arg(p->va, unsigned long);
	if (!(p->precision) && u == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_lu(u, p);
	while (p->padding-- > (p->precision > len_ulong(u, 10) ?
				p->precision : len_ulong(u, 10))
			&& ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_lu(u, p);
	return (ret);
}

int		fmt_lx(t_param *p)
{
	unsigned long	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(p->va, unsigned long);
	if (!(p->precision) && x == 0)
		return (print_spaces(p));
	ln = (p->precision > len_ulong(x, 16)) ? p->precision : len_ulong(x, 16)
		+ 2 * (p->flags[HASH] && x != 0);
	if (p->flags[LEFT])
		ret += print_lx(x, p);
	if (p->flags[ZPAD] && !p->precision && !p->flags[LEFT])
		while (p->padding-- > ln && ret++)
			pchar('0');
	while (!p->flags[ZPAD] && p->padding-- > ln && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_lx(x, p);
	return (ret);
}

int		fmt_lbx(t_param *p)
{
	unsigned long	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(p->va, unsigned long);
	if (!(p->precision) && x == 0)
		return (print_spaces(p));
	ln = (p->precision > len_ulong(x, 16)) ? p->precision : len_ulong(x, 16)
		+ 2 * (p->flags[HASH] && x != 0);
	if (p->flags[LEFT])
		x += print_lbx(x, p);
	if (p->flags[ZPAD] && !p->precision && !p->flags[LEFT])
		while (p->padding-- > ln && ret++)
			pchar('0');
	while (!p->flags[ZPAD] && p->padding-- > ln && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		x += print_lbx(x, p);
	return (ret);
}
