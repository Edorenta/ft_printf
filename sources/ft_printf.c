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

int		print_spaces(int p->flags)
{
	int		n;

	n = flags[PAD];
	while (n--)
		pchar(32);
	return (flags[PAD]);
}

int		print_pct(int p->flags)
{
	int		ret;

	ret = 0;
	if (flags[LEFT])
		pchar('%');
	while (flags[PAD]-- > 1 && ret++)
		flags[ZPAD] ? pchar('0') : pchar(' ');
	if (!flags[LEFT])
		pchar('%');
	return (++ret);
}

void	eval_format(const char *str, t_param p)
{
	if (str[p->i + 1] == 0)
		return ;
	p->i++;
	if (!eof(*str))
		get_padding(str, p);
	else
		get_precision(str, p->flags, va);
	if (p->flags[PAD] < 0)
	{
		p->flags[PAD] *= -1;
		p->flags[LEFT] = 1;
	}
	if (str[p->i] == 'j')
		(p->flags)[9] = 1;
	else
		get_length(str, flags);
	p->i++;
	if (is_length_modifier(p->flags) && str[p->i] != 'p')
		fmt_mods(str, p->flags, va, ret);
	else
		fmt_handle(str, p->flags, va, ret);
}

int		ft_printf(const char *str, ...)
{
	t_param	p;

	p.i = 0;
	p.j = 0;
	p.flags = (int *)malloc(sizeof(int) * 16)
	va_start(p.va, str);
	while (str[p.i])
	{
		if (str[p.i] == '%')
			eval_format(str, &p);
		else
		{
			pchar(str[p.i]);
			p.j++;
		}
		p.i++;
	}
	va_end(p.va);
	free(p.flags);
	return (p.j);
}
