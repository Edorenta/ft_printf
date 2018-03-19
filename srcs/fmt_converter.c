/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** fta_itoa_base appends "n" expressed in base "b" onto the string "sstr"
** if the first bit of "mask" is on, capital letters will be used
** for alphadecimal bases (greater than base 10)
** the above achieved by passing bases as negative values to the function
** if the second bit of "mask" is on, "n" is considered unsigned
*/

int						fta_itoa_base(t_array *sstr, intmax_t n,
								int b, char mask)
{
	int					ret;
	const uintmax_t		un = (uintmax_t)n;
	const char			*base =

	(mask & 1 ? BASE_UCASE : BASE_LCASE);
	ret = 1;
	if (mask & 2 ? (uintmax_t)b <= un : n <= -b || b <= n)
		ret += fta_itoa_base(sstr, (mask & 2 ?
			(intmax_t)(un / b) : n / b), b, mask);
	fta_append(sstr, (void *)(base +
		(mask & 2 ? (size_t)(un % b) : ABS(n % b))), 1);
	return (ret);
}

/*
** special check for floating point limits infinity and NaNs (f/F)
*/

static inline int		check_extrema(t_array *sstr, long double x, char mask)
{
	if (ft_isinf(x))
	{
		if (mask & 1)
			fta_append(sstr, "INFINITY", 8);
		else
			fta_append(sstr, "infinity", 8);
		return (1 + 8);
	}
	if (ft_isnan(x))
	{
		if (mask & 1)
			fta_append(sstr, "NAN", 3);
		else
			fta_append(sstr, "nan", 3);
		return (4);
	}
	return (0);
}

/*
** fta_dtoa_base appends "n" expressed in base "b" onto the string "sstr"
** if the first bit of "mask" is on, capital letters will be used
** for alphadecimal bases (greater than base 10) and NAN/INF returns
** if the second bit of "mask" is on, "n" is considered unsigned
** this is achieved by passing bases as negative values to the function
*/

int						fta_dtoa_base(t_array *sstr, long double x,
								int b, char mask)
{
	double				mantissa;
	double				intg;
	int					ret;
	int					check;
	const char			*base =

	(mask & 1 ? BASE_UCASE : BASE_LCASE);
	if ((check = check_extrema(sstr, x, mask)))
		return (check);
	ret = 1 + fta_itoa_base(sstr, (long long)x, b, mask);
	fta_append(sstr, ",", 1);
	while ((mantissa = ft_modf(x, &intg)) != 0.)
	{
		x *= b;
		fta_append(sstr, (void *)base + ((long long)x % b), 1);
		ret++;
	}
	return (ret);
}
