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

int		fmt_s(va_list *va, int *flags)
{
	int		ret;
	char	*s;
	int		lw;

	ret = 0;
	if (flags[13])
	{
		while (flags[PAD]-- && ret++)
			pchar(32);
		return (ret);
	}
	s = va_arg(*va, char *);
	if (flags[12] && flags[12] < (int)slen(s) && flags[12] >= 0)
		lw = flags[12];
	else
		lw = s ? slen(s) : 6;
	if (flags[LEFT])
		ret += print_s(s, flags);
	while (flags[PAD]-- > lw && ret++ > -1)
		pchar(32);
	if (!flags[LEFT])
		ret += print_s(s, flags);
	return (ret);
}

int		fmt_bs(va_list *va, int *flags)
{
	int				ret;
	unsigned int	*bs;

	ret = 0;
	if (flags[13])
	{
		while (flags[PAD]-- && ret++ > -1)
			pchar(32);
		return (ret);
	}
	bs = va_arg(*va, unsigned int *);
	if (flags[LEFT])
		ret += print_bs(bs);
	while (flags[PAD]-- > uitab_len(bs) && ret++ > -1)
		pchar(32);
	if (!flags[LEFT])
		ret += print_bs(bs);
	return (ret);
}

int		fmt_p(va_list *va, int *flags)
{
	int		ret;
	long	p;

	ret = 0;
	p = va_arg(*va, long);
	if (flags[LEFT])
		ret += print_p(p, flags);
	while (flags[PAD]-- > len_long(p, 16) + 2 && ret++ > -1)
		pchar(32);
	if (!flags[LEFT])
		ret += print_p(p, flags);
	return (ret);
}

int		fmt_c(va_list *va, int *flags)
{
	int		ret;
	int		c;

	ret = flags[11] ? flags[11] : 1;
	c = va_arg(*va, int);
	if (flags[2])
		pchar(c);
	while (flags[11]-- > 1)
		pchar(' ');
	if (!flags[2])
		pchar(c);
	return (ret);
}

int		fmt_bc(va_list *va, int *flags)
{
	int					ret;
	unsigned int		bc;

	ret = 0;
	bc = va_arg(*va, unsigned int);
	if (flags[2])
		ret += print_bc(bc);
	while (flags[11]-- > (int)get_nb_bytes(bc) && ret++)
		pchar(' ');
	if (!flags[2])
		ret += print_bc(bc);
	return (ret);
}