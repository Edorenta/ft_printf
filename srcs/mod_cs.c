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

int		fmt_s(t_param *p)
{
	int		ret;
	char	*s;
	int		lw;

	ret = 0;
	if ((p->precision))
	{
		while (p->padding-- && ret++)
			pchar(32);
		return (ret);
	}
	s = va_arg(p->va, char *);
	if (p->precision && p->precision < (int)slen(s))
		lw = p->precision;
	else
		lw = s ? slen(s) : 6;
	if (p->flags[LEFT])
		ret += print_s(s, p);
	while (p->padding-- > lw && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_s(s, p);
	return (ret);
}

int		fmt_bs(t_param *p)
{
	int				ret;
	unsigned int	*bs;

	ret = 0;
	if (p->flags[NODIGIT])
	{
		while (p->padding-- && ret++)
			pchar(32);
		return (ret);
	}
	bs = va_arg(p->va, unsigned int *);
	if (p->flags[LEFT])
		ret += print_bs(bs);
	while (p->padding-- > uitab_len(bs) && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_bs(bs);
	return (ret);
}

int		fmt_p(t_param *p)
{
	int		ret;
	long	hex;

	ret = 0;
	hex = va_arg(p->va, long);
	if (p->flags[LEFT])
		ret += print_p(hex, p);
	while (p->padding-- > len_long(hex, 16) + 2 && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_p(hex, p);
	return (ret);
}

int		fmt_c(t_param *p)
{
	int		ret;
	int		c;

	ret = p->padding ? p->padding : 1;
	c = va_arg(p->va, int);
	if (p->flags[LEFT])
		pchar(c);
	while (p->padding-- > 1)
		pchar(32);
	if (!p->flags[LEFT])
		pchar(c);
	return (ret);
}

int		fmt_bc(t_param *p)
{
	int					ret;
	unsigned int		bc;

	ret = 0;
	bc = va_arg(p->va, unsigned int);
	if (p->flags[LEFT])
		ret += print_bc(bc);
	while (p->padding-- > (int)get_nb_bytes(bc) && ret++)
		pchar(32);
	if (!p->flags[LEFT])
		ret += print_bc(bc);
	return (ret);
}