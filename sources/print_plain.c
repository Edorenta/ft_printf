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

int		print_s(char *s, int *flags)
{
	const	char	*nu = "(null)";
	int				i;
	int				len;

	i = -1;
	if (!s)
	{
		if (flags[12] && flags[12] < 6 && flags[12] >= 0)
			len = flags[12];
		else
			len = 6;
		while (++i < len)
			pchar(nu[i]);
		return (i);
	}
	if (flags[12] && flags[12] < (int)slen(s) && flags[12] >= 0)
		len = flags[12];
	else
		len = slen(s);
	while (++i < len)
		pchar(s[i]);
	return (i);
}

int		print_d(int d, int *flags)
{
	int		ret;
	int		ici;
	int		q;

	q = 0;
	ici = 0;
	ret = 0;
	if ((flags[3] || flags[4]) && d >= 0)
	{
		*ici = 1;
		pchar (flag[3] ? '+' : 32)
		(*ret)++;
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
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > len_int(d, 10) + ici && ret++ > -1)
			pchar('0');
	while (flags[12]-- > len_int(d, 10) && ret++ > -1)
		pchar('0');
	pnbr(d);
	ret += len_int(d, 10) - q;
	return (ret);
}

int		print_bd(long d, int *flags)
{
	int		ret;
	int		q;
	int		ici;

	q = 0;
	ici = 0;
	ret = 0;
	if ((flags[3] || flags[4]) && d >= 0)
	{
		ici = 1;
		pchar (flag[3] ? '+' : 32)
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
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > len_long(d, 10) + ici && ret++ > -1)
			pchar('0');
	while (flags[12]-- > len_long(d, 10) && ret++ > -1)
		pchar('0');
	plong_base(d, 10);
	ret += len_long(d, 10) - q;
	return (ret);
}

int		print_o(int d, int *flags)
{
	int		ret;
	int		b;

	b = (d != 0) && flags[0] && (flags[12] <= len_int(d, 8));
	if (b)
		pchar('0');
	ret = b;
	while (flags[12]-- > b + len_int(d, 8) && ret++ > -1)
		pchar('0');
	if (d < 0)
		pnbr_oct(d);
	else
		pnbr_base(d, 8);
	ret += d < 0 ? 11 : len_int(d, 8);
	return (ret);
}

int		print_bo(long d, int *flags)
{
	int		ret;
	int		b;

	b = (d != 0) && flags[0] && (flags[12] <= len_long(d, 8));
	if (b)
		pchar('0');
	ret = b;
	while (flags[12]-- > b + len_long(d, 8) && ret++ > -1)
		pchar('0');
	if (d < 0)
		plong_oct(d);
	else
		plong_base(d, 8);
	ret += d < 0 ? 22 : len_long(d, 8);
	return (ret);
}
