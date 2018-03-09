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
# include <stdarg.h>
# include <limits.h>
# include "formats.h"

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
# define _Z_			10
# define _J_
# define PAD			11

static	const	char	*base_ucase = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static	const	char	*base_lcase = "0123456789abcdefghijklmnopqrstuvwxyz";

typedef struct	s_convert
{
	int			(*fmt_tab)(va_list *, int *);
}				t_convert;

typedef struct		s_param
{
	int			    *flags;
	va_list			va;
	size_t			i1;
	size_t			i2;

	unsigned int    width;
	unsigned int    precision;
	unsigned int    base;
	bool			neg;
}					t_param;

unsigned int	get_nb_bytes(unsigned int car);
int				eof(char *str);
int				ft_printf(const char *str, ...);
void			get_padding(char **str, int **flags, va_list *ap);
void			get_precision(char **str, int **flags, va_list *ap);
void			get_length(char **str, int **flags);
int				is_length_modifier(int *flags);
int				len_int(int n, int base);
int				len_long(long n, long base);
int				len_uint(unsigned int n, unsigned int base);
int				len_ulong(unsigned long n, unsigned long base);
int				len_ull(unsigned long long n, unsigned long long base);
int				len_ll(long long n, long long base);
int				uitab_len(unsigned int *s);
void			pnbr_base(int n, int base);
void			pnbr_base_ucase(int n, int base);
void			plong_base(long n, long base);
void			pulong_base(unsigned long n, unsigned long base);
void			pulong_base_up(unsigned long n, unsigned long base);
void			pull_base(unsigned long long n, unsigned long long base);
void			pll_base(long long n, long long base);
void			pull_base_up(unsigned long long n, unsigned long long base);
void			puint_base(unsigned int n, unsigned int base);
void			puint_base_up(unsigned int n, unsigned int base);
void			pnbr_oct(int n);
void			plong_oct(long n);
int				print_bc(unsigned int car);
int				print_bs(unsigned int *bs);
int				print_s(char *s, int *flags);
int				print_d(int d, int *flags);
int				print_bd(long d, int *flags);
int				print_o(int d, int *flags);
int				print_bo(long d, int *flags);
int				print_u(unsigned int d, int *flags);
int				print_bu(unsigned long d, int *flags);
int				print_p(long p, int *flags);
int				print_x(unsigned int x, int *flags);
int				print_bx(unsigned int x, int *flags);
int				print_jd(intmax_t d, int *flags);
int				print_jo(uintmax_t d, int *flags);
int				print_ju(uintmax_t d, int *flags);
int				print_jx(uintmax_t x, int *flags);
int				print_jbx(uintmax_t x, int *flags);
int				print_ld(long x, int *flags);
int				print_lo(unsigned long x, int *flags);
int				print_lu(unsigned long x, int *flags);
int				print_lx(unsigned long x, int *flags);
int				print_lbx(unsigned long x, int *flags);
int				print_zd(long d, int *flags);
int				print_zo(size_t x, int *flags);
int				print_zu(size_t x, int *flags);
int				print_zx(size_t x, int *flags);
int				print_zbx(size_t x, int *flags);
int				print_pct(int *flags);
int				print_spaces(int *flags);

#endif
