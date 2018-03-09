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

int		fmt_ld(va_list *va, int *flags)
{
	long	d;
	int		ret;
	int		prec;

	prec = flags[12];
	ret = 0;
	d = va_arg(*va, long);
	if (flags[13] && d == 0)
		return (print_spaces(flags));
	if (flags[2])
		ret += print_ld(d, flags);
	if ((!flags[1] || flags[2] || prec) && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > len_long(ABS(d), 10)) +
				(prec > len_long(d, 10) ? prec :
				len_long(d, 10)) && ret++ > -1)
			pchar(' ');
	if (!flags[2])
		ret += print_ld(d, flags);
	return (ret);
}

int		fmt_lo(va_list *va, int *flags)
{
	unsigned long	o;
	int				ret;
	int				prec;

	prec = flags[12];
	ret = 0;
	o = va_arg(*va, unsigned long);
	if (flags[13] && o == 0 && !flags[0])
		return (print_spaces(flags));
	if (flags[2])
		ret += print_lo(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > len_ulong(o, 8) && ret++ > -1)
			pchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > len_ulong(o, 8) ? flags[12] :
			len_ulong(o, 8)) && ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_lo(o, flags);
	return (ret);
}

int		fmt_lu(va_list *va, int *flags)
{
	unsigned long	u;
	int				ret;

	ret = 0;
	u = va_arg(*va, unsigned long);
	if (flags[13] && u == 0)
		return (print_spaces(flags));
	if (flags[2])
		ret += print_lu(u, flags);
	while (flags[11]-- > (flags[12] > len_ulong(u, 10) ?
				flags[12] : len_ulong(u, 10))
			&& ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_lu(u, flags);
	return (ret);
}

int		fmt_lx(va_list *va, int *flags)
{
	unsigned long	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(*va, unsigned long);
	if (flags[13] && x == 0)
		return (print_spaces(flags));
	ln = (flags[12] > len_ulong(x, 16)) ? flags[12] : len_ulong(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_lx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			pchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_lx(x, flags);
	return (ret);
}

int		fmt_lbx(va_list *va, int *flags)
{
	unsigned long	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(*va, unsigned long);
	if (flags[13] && x == 0)
		return (print_spaces(flags));
	ln = (flags[12] > len_ulong(x, 16)) ? flags[12] : len_ulong(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		x += print_lbx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			pchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		pchar(' ');
	if (!flags[2])
		x += print_lbx(x, flags);
	return (ret);
}
