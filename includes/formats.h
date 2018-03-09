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

void	fmt_handle(char **str, int *flags, va_list *ap, int *ret);
void	fmt_mods(char **str, int *flags, va_list *ap, int *ret);
int		fmt_s(va_list *ap, int *flags);
int		fmt_bs(va_list *ap, int *flags);
int		fmt_p(va_list *ap, int *flags);
int		fmt_d(va_list *ap, int *flags);
int		fmt_bd(va_list *ap, int *flags);
int		fmt_i(va_list *ap, int *flags);
int		fmt_o(va_list *ap, int *flags);
int		fmt_bo(va_list *ap, int *flags);
int		fmt_u(va_list *ap, int *flags);
int		fmt_bu(va_list *ap, int *flags);
int		fmt_x(va_list *ap, int *flags);
int		fmt_bx(va_list *ap, int *flags);
int		fmt_c(va_list *ap, int *flags);
int		fmt_bc(va_list *ap, int *flags);
int		fmt_b(va_list *ap, int *flags);
int		fmt_hhd(va_list *ap, int *flags);
int		fmt_hho(va_list *ap, int *flags);
int		fmt_hhu(va_list *ap, int *flags);
int		fmt_hhx(va_list *ap, int *flags);
int		fmt_hhbx(va_list *ap, int *flags);
int		fmt_hd(va_list *ap, int *flags);
int		fmt_ho(va_list *ap, int *flags);
int		fmt_hu(va_list *ap, int *flags);
int		fmt_hx(va_list *ap, int *flags);
int		fmt_hbx(va_list *ap, int *flags);
int		fmt_lld(va_list *ap, int *flags);
int		fmt_llo(va_list *ap, int *flags);
int		fmt_llu(va_list *ap, int *flags);
int		fmt_llx(va_list *ap, int *flags);
int		fmt_llbx(va_list *ap, int *flags);
int		fmt_ld(va_list *ap, int *flags);
int		fmt_lo(va_list *ap, int *flags);
int		fmt_lu(va_list *ap, int *flags);
int		fmt_lx(va_list *ap, int *flags);
int		fmt_lbx(va_list *ap, int *flags);
int		fmt_jd(va_list *ap, int *flags);
int		fmt_jo(va_list *ap, int *flags);
int		fmt_ju(va_list *ap, int *flags);
int		fmt_jx(va_list *ap, int *flags);
int		fmt_jbx(va_list *ap, int *flags);
int		fmt_zd(va_list *ap, int *flags);
int		fmt_zo(va_list *ap, int *flags);
int		fmt_zu(va_list *ap, int *flags);
int		fmt_zx(va_list *ap, int *flags);
int		fmt_zbx(va_list *ap, int *flags);

#endif
