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

int		fmt_lld(t_param *p)
{
	long long	d;
	int			ret;

	ret = 0;
	d = va_arg(p->va, long long);
	if (p->flags[NODIGIT] && d == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_jd(d, p);
	if ((!p->flags[ZPAD] || p->flags[LEFT] || p->precision) && p->padding)
		while (p->padding-- > (p->flags[PLUS] || p->flags[SPACE])
				+ (d < 0 && p->precision > len_ll(ABS(d), 10)) +
				(p->precision > len_ll(d, 10) ? p->precision : len_ll(d, 10))
				&& ret++)
			pchar(32);
	if (!p->flags[LEFT])
		ret += print_jd(d, p);
	return (ret);
}

int		fmt_llo(t_param *p)
{
	unsigned long long	o;
	int					ret;

	ret = 0;
	o = va_arg(p->va, unsigned long long);
	if (p->flags[NODIGIT] && o == 0 && !p->flags[HASH])
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_jo(o, p);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > len_ull(o, 8) && ret++)
			pchar('0');
	while (p->padding-- > (p->flags[HASH] && o != 0) +
			(p->precision > len_ull(o, 8) ? p->precision : len_ull(o, 8))
			&& ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_jo(o, p);
	return (ret);
}

int		fmt_llu(t_param *p)
{
	unsigned long long	u;
	int					ret;

	ret = 0;
	u = va_arg(p->va, unsigned long long);
	if (p->flags[NODIGIT] && u == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_ju(u, p);
	while (p->padding-- > (p->precision > len_ull(u, 10) ?
				p->precision : len_ull(u, 10))
			&& ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_ju(u, p);
	return (ret);
}

int		fmt_llx(t_param *p)
{
	unsigned long long	x;
	int					ret;
	int					ln;

	ret = 0;
	x = va_arg(p->va, unsigned long long);
	if (p->flags[NODIGIT] && x == 0)
		return (print_spaces(p));
	ln = (p->precision > len_ull(x, 16)) ? p->precision : len_ull(x, 16)
		+ 2 * (p->flags[HASH] && x != 0);
	if (p->flags[LEFT])
		ret += print_jx(x, p);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > ln && ret++)
			pchar('0');
	while (!p->flags[ZPAD] && p->padding-- > ln && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_jx(x, p);
	return (ret);
}

int		fmt_llbx(t_param *p)
{
	unsigned long long	x;
	int					ret;
	int					ln;

	ret = 0;
	x = va_arg(p->va, unsigned long long);
	if (p->flags[NODIGIT] && x == 0)
		return (print_spaces(p));
	ln = (p->precision > len_ull(x, 16)) ? p->precision : len_ull(x, 16)
		+ 2 * (p->flags[HASH] && x != 0);
	if (p->flags[LEFT])
		ret += print_jbx(x, p);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > ln && ret++)
			pchar('0');
	while (!p->flags[ZPAD] && p->padding-- > ln && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_jbx(x, p);
	return (ret);
}
