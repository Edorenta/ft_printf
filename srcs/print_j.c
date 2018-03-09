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

int		print_jd(intmax_t d, int *flags)
{
	int		ret;
	int		ici;
	int		q;

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
		q = d == LLONG_MIN ? 1 : 0;
		if (!q)
			pchar('-');
		ret++;
		d = -d;
	}
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > len_ll(d, 10) + ici && ret++ > -1)
			pchar('0');
	while (flags[12]-- > len_ll(d, 10) && ret++ > -1)
		pchar('0');
	pll_base(d, 10);
	ret += len_ll(d, 10);
	return (ret);
}

int		print_jo(uintmax_t d, int *flags)
{
	int		ret;
	int		b;

	b = (d != 0) && flags[0] && (flags[12] <= len_ull(d, 8));
	if (b)
		pchar('0');
	ret = b;
	while (flags[12]-- > b + len_ull(d, 8) && ret++ > -1)
		pchar('0');
	pull_base(d, 8);
	ret += len_ull(d, 8);
	return (ret);
}

int		print_ju(uintmax_t d, int *flags)
{
	int		ret;

	ret = 0;
	while (flags[12]-- > len_ull(d, 10) && ret++ > -1)
		pchar('0');
	pull_base(d, 10);
	ret += len_ull(d, 10);
	return (ret);
}

int		print_jx(uintmax_t x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		pstr("0x");
	ret = 2 * b;
	while (flags[12]-- > len_ull(x, 16) && ret++ > -1)
		pchar('0');
	pull_base(x, 16);
	ret += len_ull(x, 16);
	return (ret);
}

int		print_jbx(uintmax_t x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		pstr("0X");
	ret = 2 * b;
	while (flags[12]-- > len_ull(x, 16) && ret++ > -1)
		pchar('0');
	pull_base_up(x, 16);
	ret += len_ull(x, 16);
	return (ret);
}
