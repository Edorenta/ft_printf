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

int		fmt_hd(va_list *va, int *flags)
{
	short	d;
	int		ret;
	int		prec;

	prec = flags[12];
	ret = 0;
	d = va_arg(*va, int);
	if (flags[13] && d == 0)
		return (print_spaces(flags));
	if (flags[2])
		ret += print_d(d, flags);
	if ((!flags[1] || flags[2] || prec) && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > len_int(ABS(d), 10)) +
				(prec > len_int(d, 10) ? prec : len_int(d, 10))
				&& ret++ > -1)
			pchar(' ');
	if (!flags[2])
		ret += print_d(d, flags);
	return (ret);
}

int		fmt_ho(va_list *va, int *flags)
{
	unsigned short	o;
	int				ret;
	int				prec;

	prec = flags[12];
	ret = 0;
	o = va_arg(*va, int);
	if (flags[13] && o == 0 && !flags[0])
		return (print_spaces(flags));
	if (flags[2])
		ret += print_o(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > len_int(o, 8) && ret++ > -1)
			pchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > len_int(o, 8) ? flags[12] : len_int(o, 8))
			&& ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_o(o, flags);
	return (ret);
}

int		fmt_hu(va_list *va, int *flags)
{
	unsigned short	u;
	int				ret;

	ret = 0;
	u = va_arg(*va, int);
	if (flags[13] && u == 0)
		return (print_spaces(flags));
	if (flags[2])
		ret += print_u(u, flags);
	while (flags[11]-- > (flags[12] > len_uint(u, 10) ?
				flags[12] : len_uint(u, 10))
			&& ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_u(u, flags);
	return (ret);
}

int		fmt_hx(va_list *va, int *flags)
{
	unsigned short	x;
	int				ret;
	int				ln;

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

int		fmt_hbx(va_list *va, int *flags)
{
	unsigned short	x;
	int				ret;
	int				ln;

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
