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

int		fmt_x(va_list *va, int *flags)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(*va, int);
	if (flags[13] && x == 0)
		return (print_spaces(flags));
	ln = (flags[12] > len_uint(x, 16)) ? flags[12] : len_uint(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_x(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			pchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_x(x, flags);
	return (ret);
}

int		fmt_bx(va_list *va, int *flags)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(*va, int);
	if (flags[13] && x == 0)
		return (print_spaces(flags));
	ln = (flags[12] > len_uint(x, 16)) ? flags[12] : len_uint(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_bx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			pchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_bx(x, flags);
	return (ret);
}

int		fmt_b(va_list *va, int *flags)
{
	int		ret;
	int		b;

	ret = 0;
	b = va_arg(*va, int);
	if (flags[13] && b == 0)
		return (print_spaces(flags));
	if (flags[2])
		pnbr_base(b, 2);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > len_int(b, 2) && ret++ > -1)
			pchar('0');
	while (!flags[1] && flags[11]-- > len_int(b, 2) && ret++ > -1)
		pchar(' ');
	if (!flags[2])
		pnbr_base(b, 2);
	ret += len_int(b, 2);
	return (ret);
}

int		fmt_d(va_list *va, int *flags)
{
	int		d;
	int		ret;
	int		prec;

	prec = flags[12];
	ret = 0;
	d = va_arg(*va, int);
	if (flags[13] && d == 0)
		return (0);
	if (flags[LEFT])
		ret += print_d(d, flags);
	if ((!flags[1] || flags[LEFT] || prec) && flags[PAD])
		while (flags[PAD]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > len_int(ABS(d), 10)) +
				(prec > len_int(d, 10) ? prec :
				len_int(d, 10)) && ret++ > -1)
			pchar(32);
	if (!flags[LEFT])
		ret += print_d(d, flags);
	return (ret);
}

int		fmt_bd(va_list *va, int *flags)
{
	int		ret;
	long	bd;

	ret = 0;
	bd = va_arg(*va, long);
	if (flags[13] && bd == 0)
		return (0);
	if (flags[LEFT])
		ret += print_bd(bd, flags);
	if (!flags[1] && flags[PAD])
		while (flags[PAD]-- > (flags[3] || flags[4])
				+ (bd < 0 && flags[12] > len_long(bd, 10))
				+ (flags[12] > len_long(bd, 10) ?
					flags[12] : len_long(bd, 10))
				&& ret++ > -1)
			pchar(32);
	if (!flags[LEFT])
		ret += print_bd(bd, flags);
	return (ret);
}