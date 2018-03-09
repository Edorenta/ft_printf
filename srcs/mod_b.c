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

int		fmt_i(va_list *va, int *flags)
{
	return (fmt_d(va, flags));
}

int		fmt_o(va_list *va, int *flags)
{
	int		ret;
	int		o;
	int		prec;

	prec = flags[12];
	ret = 0;
	o = va_arg(*va, int);
	if (flags[13] && o == 0 && !flags[0])
		return (print_spaces(flags));
	if (flags[2])
		ret += print_o(o, flags);
	if (flags[1] && !prec && !flags[2])
		while (flags[11]-- > len_int(o, 8) && ret++ > -1)
			pchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(prec > len_int(o, 8) ? prec : len_int(o, 8))
			&& ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_o(o, flags);
	return (ret);
}

int		fmt_bo(va_list *va, int *flags)
{
	int		ret;
	long	o;

	ret = 0;
	o = va_arg(*va, long);
	if (flags[13] && !flags[0] && o == 0)
		return (print_spaces(flags));
	if (flags[2])
		ret += print_bo(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > len_long(o, 8) && ret++ > -1)
			pchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > len_long(o, 8) ? flags[12] : len_long(o, 8))
			&& ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_bo(o, flags);
	return (ret);
}

int		fmt_u(va_list *va, int *flags)
{
	int				ret;
	unsigned int	u;

	ret = 0;
	u = va_arg(*va, unsigned int);
	if (flags[13] && u == 0)
		return (print_spaces(flags));
	if (flags[2])
		ret += print_u(u, flags);
	while (flags[11]-- > (flags[12] > len_uint(u, 10) ?
				flags[12] : len_uint(u, 10))
			&& ret++ > -1)
		flags[1] ? pchar('0') : pchar(' ');
	if (!flags[2])
		ret += print_u(u, flags);
	return (ret);
}

int		fmt_bu(va_list *va, int *flags)
{
	int				ret;
	unsigned long	u;

	ret = 0;
	u = va_arg(*va, unsigned long);
	if (flags[13] && u == 0)
		return (print_spaces(flags));
	if (flags[2])
		ret += print_bu(u, flags);
	while (flags[11]-- > (flags[12] > len_ulong(u, 10) ?
				flags[12] : len_ulong(u, 10))
			&& ret++ > -1)
		pchar(' ');
	if (!flags[2])
		ret += print_bu(u, flags);
	return (ret);
}
