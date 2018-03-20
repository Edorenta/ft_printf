/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:37:29 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:08:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#include "parsing.h"
#include "private_macros.h"
#include "string_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

#include <stdio.h>

static int get_decimals(double n, uint8_t base, uint8_t precision)
{
	int tmp;

	tmp = MIN(ft_decimals(n, base), precision);
	return (MAX(tmp, 2));
}
/*
char *ft_ftoa_base(double n, uint8_t base, uint8_t precision)
{
	long long	tmp[3];
	int			digits[2];
	int			i;
	char		*str;

	tmp[0] = ft_getll(n);
	digits[0] = ft_ddigits(ft_dabs(n), base) + 1;
	digits[1] = get_decimals(ft_dabs(n), base, precision);
	tmp[1] = ft_getll(ft_dpow(10, digits[1]) * ft_getfrac(ft_dabs(n)));
	dprintf(1, "digits: %d dec: %d\n", digits[0], digits[1]);
	i = ((n < 0 && base == 10) ? 1 : 0) + digits[0] + digits[1] - 1;
	if (!(str = (char *)malloc(sizeof(char) * i + 3)))
		return ((void *)0);
	i = -1;
	if ((n < 0 && base == 10))
		str[++i] = '-';
	while (--digits[0])
	{
		tmp[2] = tmp[0] / ft_llpow(base, digits[0]);
		str[++i] = BASE_LCASE[(int)tmp[2]];
		tmp[0] -= (tmp[2] * ft_llpow(base, digits[0]));
	}
	str[++i] = BASE_LCASE[(int)tmp[0]];
	str[++i] = '.';
	while (digits[1] && --digits[1])
	{
		tmp[2] = tmp[1] / ft_llpow(base, digits[1]);
		printf("tmp2: %lld\n", tmp[2]);
		str[++i] = BASE_LCASE[(int)tmp[2]];
		tmp[1] -= (tmp[2] * ft_llpow(base, digits[1]));
	}
	str[++i] = BASE_LCASE[(int)tmp[1]];
	str[++i] = '\0';
	return (str);
}
*/
char *ft_ftoa_base(double n, uint8_t base, uint8_t precision)
{
	long long	tmp[3];
	int			digits[2];
	int			i;
	char		*str;

	tmp[0] = ft_getll(n);
	digits[0] = ft_ddigits(ft_dabs(n), base) + 1;
	digits[1] = get_decimals(ft_dabs(n), base, precision);
	tmp[1] = ft_getll(ft_dpow(10, digits[1]) * ft_getfrac(ft_dabs(n)));
	dprintf(1, "digits: %d dec: %d\n", digits[0], digits[1]);
	i = ((n < 0 && base == 10) ? 1 : 0) + digits[0] + digits[1] - 1;
	if (!(str = (char *)malloc(sizeof(char) * i + 3)))
		return ((void *)0);
	str = ft_strdup(ft_lltoa_base(tmp[0], base));
	ft_strcat(str, ".\0");
	ft_strcat(str, ft_lltoa_base(tmp[1], base));
	return (str);
}
