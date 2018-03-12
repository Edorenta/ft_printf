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

static	void	eval_format(const char *str, t_param *p)
{
	if (str[p->i] && str[p->i + 1])
	{
		p->i++;
		if (str[p->i] == '0' || str[p->i] == '#' || str[p->i] == 32
			|| str[p->i] == '-' || str[p->i] == '+')
			get_padding(str, p);
		get_precision(str, p);
		get_len(str, p);
		p->i++;
		if (is_len_mod(p) && str[p->i] != 'p')
			fmt_mods(str, p);
		else
			fmt_handle(str, p);
	}
}

static	void	set_adv_tab2(t_param *p)
{
	p->adv_conv[18].ptr = &fmt_ld;
	p->adv_conv[19].ptr = &fmt_ld;
	p->adv_conv[20].ptr = &fmt_lo;
	p->adv_conv[21].ptr = &fmt_lu;
	p->adv_conv[22].ptr = &fmt_lx;
	p->adv_conv[23].ptr = &fmt_lbx;
	p->adv_conv[24].ptr = &fmt_jd;
	p->adv_conv[25].ptr = &fmt_jd;
	p->adv_conv[26].ptr = &fmt_jo;
	p->adv_conv[27].ptr = &fmt_ju;
	p->adv_conv[28].ptr = &fmt_jx;
	p->adv_conv[29].ptr = &fmt_jbx;
	p->adv_conv[30].ptr = &fmt_zd;
	p->adv_conv[31].ptr = &fmt_zd;
	p->adv_conv[32].ptr = &fmt_zo;
	p->adv_conv[33].ptr = &fmt_zu;
	p->adv_conv[34].ptr = &fmt_zx;
	p->adv_conv[35].ptr = &fmt_zbx;
}

static	void	set_adv_tab(t_param *p)
{
	p->adv_conv[0].ptr = &fmt_hhd;
	p->adv_conv[1].ptr = &fmt_hhd;
	p->adv_conv[2].ptr = &fmt_hho;
	p->adv_conv[3].ptr = &fmt_hhu;
	p->adv_conv[4].ptr = &fmt_hhx;
	p->adv_conv[5].ptr = &fmt_hhbx;
	p->adv_conv[6].ptr = &fmt_hd;
	p->adv_conv[7].ptr = &fmt_hd;
	p->adv_conv[8].ptr = &fmt_ho;
	p->adv_conv[9].ptr = &fmt_hu;
	p->adv_conv[10].ptr = &fmt_hx;
	p->adv_conv[11].ptr = &fmt_hbx;
	p->adv_conv[12].ptr = &fmt_lld;
	p->adv_conv[13].ptr = &fmt_lld;
	p->adv_conv[14].ptr = &fmt_llo;
	p->adv_conv[15].ptr = &fmt_llu;
	p->adv_conv[16].ptr = &fmt_llx;
	p->adv_conv[17].ptr = &fmt_llbx;
}

static	void	set_basic_tab(t_param *p)
{
	p->basic_conv[0].ptr = &fmt_s;
	p->basic_conv[1].ptr = &fmt_bs;
	p->basic_conv[2].ptr = &fmt_p;
	p->basic_conv[3].ptr = &fmt_d;
	p->basic_conv[4].ptr = &fmt_bd;
	p->basic_conv[5].ptr = &fmt_i;
	p->basic_conv[6].ptr = &fmt_o;
	p->basic_conv[7].ptr = &fmt_bo;
	p->basic_conv[8].ptr = &fmt_u;
	p->basic_conv[9].ptr = &fmt_bu;
	p->basic_conv[10].ptr = &fmt_x;
	p->basic_conv[11].ptr = &fmt_bx;
	p->basic_conv[12].ptr = &fmt_c;
	p->basic_conv[13].ptr = &fmt_bc;
	p->basic_conv[14].ptr = &fmt_b;
}

int						ft_printf(const char *str, ...)
{
	t_param	p;

	p.i = 0;
	p.j = 0;
	ft_bzero(p.flags, 12);
	set_basic_tab(&p);
	set_adv_tab(&p);
	set_adv_tab2(&p);
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
	return (p.j);
}
