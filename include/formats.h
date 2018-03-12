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

#ifndef FORMATS_H
# define FORMATS_H

struct		s_param;

typedef struct		s_convert
{
	int				(*ptr)(struct s_param *p);
}					t_convert;

typedef struct		s_param
{
	bool		    flags[12];
	t_convert  		basic_conv[15];
	t_convert  		adv_conv[36];
	int				padding;
    int				precision;
	va_list			va;
	size_t			i;
	size_t			j;
}					t_param;

void	fmt_handle(const char *str, t_param *p);
void	fmt_mods(const char *str, t_param *p);
int		fmt_s(t_param *p);
int		fmt_bs(t_param *p);
int		fmt_p(t_param *p);
int		fmt_d(t_param *p);
int		fmt_bd(t_param *p);
int		fmt_i(t_param *p);
int		fmt_o(t_param *p);
int		fmt_bo(t_param *p);
int		fmt_u(t_param *p);
int		fmt_bu(t_param *p);
int		fmt_x(t_param *p);
int		fmt_bx(t_param *p);
int		fmt_c(t_param *p);
int		fmt_bc(t_param *p);
int		fmt_b(t_param *p);
int		fmt_hhd(t_param *p);
int		fmt_hho(t_param *p);
int		fmt_hhu(t_param *p);
int		fmt_hhx(t_param *p);
int		fmt_hhbx(t_param *p);
int		fmt_hd(t_param *p);
int		fmt_ho(t_param *p);
int		fmt_hu(t_param *p);
int		fmt_hx(t_param *p);
int		fmt_hbx(t_param *p);
int		fmt_lld(t_param *p);
int		fmt_llo(t_param *p);
int		fmt_llu(t_param *p);
int		fmt_llx(t_param *p);
int		fmt_llbx(t_param *p);
int		fmt_ld(t_param *p);
int		fmt_lo(t_param *p);
int		fmt_lu(t_param *p);
int		fmt_lx(t_param *p);
int		fmt_lbx(t_param *p);
int		fmt_jd(t_param *p);
int		fmt_jo(t_param *p);
int		fmt_ju(t_param *p);
int		fmt_jx(t_param *p);
int		fmt_jbx(t_param *p);
int		fmt_zd(t_param *p);
int		fmt_zo(t_param *p);
int		fmt_zu(t_param *p);
int		fmt_zx(t_param *p);
int		fmt_zbx(t_param *p);

#endif
