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

void	init_conv_tab3(t_convert **conv_tab)
{
	(*conv_tab)[24].fmt_tab = &fmt_jd;
	(*conv_tab)[25].fmt_tab = &fmt_jd;
	(*conv_tab)[26].fmt_tab = &fmt_jo;
	(*conv_tab)[27].fmt_tab = &fmt_ju;
	(*conv_tab)[28].fmt_tab = &fmt_jx;
	(*conv_tab)[29].fmt_tab = &fmt_jbx;
	(*conv_tab)[30].fmt_tab = &fmt_zd;
	(*conv_tab)[31].fmt_tab = &fmt_zd;
	(*conv_tab)[32].fmt_tab = &fmt_zo;
	(*conv_tab)[33].fmt_tab = &fmt_zu;
	(*conv_tab)[34].fmt_tab = &fmt_zx;
	(*conv_tab)[35].fmt_tab = &fmt_zbx;
}

void	init_conv_tab2(t_convert **conv_tab)
{
	(*conv_tab)[0].fmt_tab = &fmt_hhd;
	(*conv_tab)[1].fmt_tab = &fmt_hhd;
	(*conv_tab)[2].fmt_tab = &fmt_hho;
	(*conv_tab)[3].fmt_tab = &fmt_hhu;
	(*conv_tab)[4].fmt_tab = &fmt_hhx;
	(*conv_tab)[5].fmt_tab = &fmt_hhbx;
	(*conv_tab)[6].fmt_tab = &fmt_hd;
	(*conv_tab)[7].fmt_tab = &fmt_hd;
	(*conv_tab)[8].fmt_tab = &fmt_ho;
	(*conv_tab)[9].fmt_tab = &fmt_hu;
	(*conv_tab)[10].fmt_tab = &fmt_hx;
	(*conv_tab)[11].fmt_tab = &fmt_hbx;
	(*conv_tab)[12].fmt_tab = &fmt_lld;
	(*conv_tab)[13].fmt_tab = &fmt_lld;
	(*conv_tab)[14].fmt_tab = &fmt_llo;
	(*conv_tab)[15].fmt_tab = &fmt_llu;
	(*conv_tab)[16].fmt_tab = &fmt_llx;
	(*conv_tab)[17].fmt_tab = &fmt_llbx;
	(*conv_tab)[18].fmt_tab = &fmt_ld;
	(*conv_tab)[19].fmt_tab = &fmt_ld;
	(*conv_tab)[20].fmt_tab = &fmt_lo;
	(*conv_tab)[21].fmt_tab = &fmt_lu;
	(*conv_tab)[22].fmt_tab = &fmt_lx;
	(*conv_tab)[23].fmt_tab = &fmt_lbx;
	init_conv_tab3(conv_tab);
}

void	init_conv_tab(t_convert **conv_tab)
{
	(*conv_tab)[0].fmt_tab = &fmt_s;
	(*conv_tab)[1].fmt_tab = &fmt_bs;
	(*conv_tab)[2].fmt_tab = &fmt_p;
	(*conv_tab)[3].fmt_tab = &fmt_d;
	(*conv_tab)[4].fmt_tab = &fmt_bd;
	(*conv_tab)[5].fmt_tab = &fmt_i;
	(*conv_tab)[6].fmt_tab = &fmt_o;
	(*conv_tab)[7].fmt_tab = &fmt_bo;
	(*conv_tab)[8].fmt_tab = &fmt_u;
	(*conv_tab)[9].fmt_tab = &fmt_bu;
	(*conv_tab)[10].fmt_tab = &fmt_x;
	(*conv_tab)[11].fmt_tab = &fmt_bx;
	(*conv_tab)[12].fmt_tab = &fmt_c;
	(*conv_tab)[13].fmt_tab = &fmt_bc;
	(*conv_tab)[14].fmt_tab = &fmt_b;
}

void	fmt_handle(const char *str, t_param *p)
{
	const char	convert = "sSpdDioOuUxXcCb";
	t_convert	*conv_tab;
	int			i;

	i = 0;
	conv_tab = malloc(15 * sizeof(t_convert));
	init_conv_tab(&conv_tab);
	while (i < 15)
	{
		if (str[p->i] == convert[i])
		{
			p->j += conv_tab[i].fmt_tab(p->av, p->flags);
			return ;
		}
		i++;
	}
	free(conv_tab);
	if (str[p->i] == '%')
		(p->j) += print_pct(p->flags);
	else
	{
		p->i--;
		p->j += print_spaces(p->flags);
	}
}

void	fmt_mods(const char *str, t_param *p)
{
	const	char	*convert = "diouxX";;
	t_convert		*conv_tab;
	int				i;

	i = 0;
	conv_tab = malloc(36 * sizeof(t_convert));
	init_conv_tab2(&conv_tab);
	while (i < 36) 
	{
		if (str[p->i] == convert[i % 6] && p->flags[i / 6 + 5])
		{
			p->j += conv_tab[i].fmt_tab(p->av, p->flags);
			return ;
		}
		i++;
	}
	free(conv_tab);
	if (str[p->i] == '%')
		p->j += print_pct(p->flags);
	else
	{
		p->i--;
		p->j += print_spaces(p->flags);
	}
}
