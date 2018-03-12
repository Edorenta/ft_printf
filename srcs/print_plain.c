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

int		print_s(char *s, t_param *p)
{
	int				i;
	int				len;

	i = -1;
	if (!s)
	{
		if (p->precision > 0 && p->precision < 6)
			len = p->precision;
		else
		{
			pstr("(null)\n");
			len = 6;
		}
	}
	else
	{
		if (p->precision > 0 && p->precision < (int)slen(s))
			len = p->precision;
		else
			len = slen(s);
		while (++i < len)
			pchar(s[i]);
	}
	return (len);
}

int		print_d(int d, t_param *p)
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
		p->flags[PLUS] ? pchar('+') : pchar(32);
		(ret)++;
	}
	if (d < 0)
	{
		ici = 1;
		q = d == -2147483648 ? 1 : 0;
		if (!q)
			pchar('-');
		ret++;
		d = -d;
	}
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > len_int(d, 10) + ici && ret++)
			pchar('0');
	while (p->precision-- > len_int(d, 10) && ret++)
		pchar('0');
	pnbr(d);
	ret += len_int(d, 10) - q;
	return (ret);
}

int		print_bd(long d, t_param *p)
{
	int		ret;
	int		q;
	int		ici;

	q = 0;
	ici = 0;
	ret = 0;
	if ((p->flags[PLUS] || p->flags[SPACE]) && d >= 0)
	{
		ici = 1;
		p->flags[PLUS] ? pchar('+') : pchar(32);
		(ret)++;
	}
	if (d < 0)
	{
		ici = 1;
		q = d == LONG_MIN ? 1 : 0;
		if (!q)
			pchar('-');
		ret++;
		d *= -1;
	}
	if (p->flags[ZPAD] && p->flags[NODIGIT] && !p->flags[LEFT])
		while (p->padding-- > len_long(d, 10) + ici && ret++)
			pchar('0');
	while (p->precision-- > len_long(d, 10) && ret++)
		pchar('0');
	plong_base(d, 10);
	ret += len_long(d, 10) - q;
	return (ret);
}

int		print_o(int d, t_param *p)
{
	int		ret;
	int		b;

	b = (d != 0) && p->flags[HASH] && (p->precision <= len_int(d, 8));
	if (b)
		pchar('0');
	ret = b;
	while (p->precision-- > b + len_int(d, 8) && ret++)
		pchar('0');
	if (d < 0)
		pnbr_oct(d);
	else
		pnbr_base(d, 8);
	ret += d < 0 ? p->padding : len_int(d, 8);
	return (ret);
}

int		print_bo(long d, t_param *p)
{
	int		ret;
	int		b;

	b = (d != 0) && p->flags[HASH] && (p->precision <= len_long(d, 8));
	if (b)
		pchar('0');
	ret = b;
	while (p->precision-- > b + len_long(d, 8) && ret++)
		pchar('0');
	if (d < 0)
		plong_oct(d);
	else
		plong_base(d, 8);
	ret += d < 0 ? 22 : len_long(d, 8);
	return (ret);
}
