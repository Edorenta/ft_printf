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

int		fmt_i(t_param *p)
{
	return (fmt_d(p));
}

int		fmt_o(t_param *p)
{
	int		ret;
	int		o;

	ret = 0;
	o = va_arg(p->va, int);
	if (p->flags[NODIGIT] && o == 0 && !p->flags[HASH])
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_o(o, p);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > len_int(o, 8) && ret++)
			pchar('0');
	while (p->padding-- > (p->flags[HASH] && o != 0) +
			(p->precision > len_int(o, 8) ? p->precision : len_int(o, 8))
			&& ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_o(o, p);
	return (ret);
}

int		fmt_bo(t_param *p)
{
	int		ret;
	long	o;

	ret = 0;
	o = va_arg(p->va, long);
	if (p->flags[NODIGIT] && !p->flags[HASH] && o == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_bo(o, p);
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > len_long(o, 8) && ret++)
			pchar('0');
	while (p->padding-- > (p->flags[HASH] && o != 0) +
			(p->precision > len_long(o, 8) ? p->precision : len_long(o, 8))
			&& ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_bo(o, p);
	return (ret);
}

int		fmt_u(t_param *p)
{
	int				ret;
	unsigned int	u;

	ret = 0;
	u = va_arg(p->va, unsigned int);
	if (p->flags[NODIGIT] && u == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_u(u, p);
	while (p->padding-- > (p->precision > len_uint(u, 10) ?
				p->precision : len_uint(u, 10)) && ret++)
		p->flags[ZPAD] ? pchar('0') : pchar(32);
	if (!p->flags[LEFT])
		ret += print_u(u, p);
	return (ret);
}

int		fmt_bu(t_param *p)
{
	int				ret;
	unsigned long	u;

	ret = 0;
	u = va_arg(p->va, unsigned long);
	if (p->flags[NODIGIT] && u == 0)
		return (print_spaces(p));
	if (p->flags[LEFT])
		ret += print_bu(u, p);
	while (p->padding-- > (p->precision > len_ulong(u, 10) ?
				p->precision : len_ulong(u, 10)) && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_bu(u, p);
	return (ret);
}
