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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include "formats.h"

# define BASE_UCASE     "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define BASE_LCASE     "0123456789abcdefghijklmnopqrstuvwxyz"
# define ABS(x) 		x < 0 ? -x : x
# define HASH			0
# define ZPAD			1
# define LEFT			2
# define PLUS			3
# define SPACE			4
# define _HH_			5
# define _H_			6
# define _LL_			7
# define _L_			8
# define _J_			9
# define _Z_			10
# define NODIGIT		11

int		        ft_atoi(const char *str);
void	        ft_bzero(void *s, size_t n);
bool            is_digit(char c);
size_t          slen(const char *str);
void            pchar(const char c);
void            pstr(const char *str);
unsigned int	get_nb_bytes(unsigned int car);
int				ft_printf(const char *str, ...);
void			get_padding(const char *str, t_param *parm);
void			get_precision(const char *str, t_param *parm);
void			get_len(const char *str, t_param *parm);
bool	    	is_len_mod(t_param *p);
int				len_int(int n, uint8_t base);
int				len_long(long n, uint8_t base);
int				len_uint(unsigned int n, uint8_t base);
int				len_ulong(unsigned long n, uint8_t base);
int				len_ull(unsigned long long n, uint8_t base);
int				len_ll(long long n, uint8_t base);
int				uitab_len(unsigned int *s);
void	        pnbr(int n);
void			pnbr_base(int n, uint8_t base);
void			pnbr_base_ucase(int n, uint8_t base);
void			plong_base(long n, uint8_t base);
void			pulong_base(unsigned long n, uint8_t base);
void			pulong_base_ucase(unsigned long n, uint8_t base);
void			pull_base(unsigned long long n, uint8_t base);
void			pll_base(long long n, uint8_t base);
void			pull_base_ucase(unsigned long long n, uint8_t base);
void			puint_base(unsigned int n, uint8_t base);
void			puint_base_ucase(unsigned int n, uint8_t base);
void			pnbr_oct(int n);
void			plong_oct(long n);
int				print_bc(unsigned int car);
int				print_bs(unsigned int *bs);
int				print_s(char *s, t_param *p);
int				print_d(int d, t_param *p);
int				print_bd(long d, t_param *p);
int				print_o(int d, t_param *p);
int				print_bo(long d, t_param *p);
int				print_u(unsigned int d, t_param *p);
int				print_bu(unsigned long d, t_param *p);
int				print_p(long hex, t_param *p);
int				print_x(unsigned int x, t_param *p);
int				print_bx(unsigned int x, t_param *p);
int				print_jd(intmax_t d, t_param *p);
int				print_jo(uintmax_t d, t_param *p);
int				print_ju(uintmax_t d, t_param *p);
int				print_jx(uintmax_t x, t_param *p);
int				print_jbx(uintmax_t x, t_param *p);
int				print_ld(long x, t_param *p);
int				print_lo(unsigned long x, t_param *p);
int				print_lu(unsigned long x, t_param *p);
int				print_lx(unsigned long x, t_param *p);
int				print_lbx(unsigned long x, t_param *p);
int				print_zd(long d, t_param *p);
int				print_zo(size_t x, t_param *p);
int				print_zu(size_t x, t_param *p);
int				print_zx(size_t x, t_param *p);
int				print_zbx(size_t x, t_param *p);
int				print_pct(t_param *p);
int				print_spaces(t_param *p);

#endif
