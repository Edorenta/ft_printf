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

int		len_int(int n, int base)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0 && base == 10)
	{
		ret++;
		if (n < -999999999)
			return (11);
		else
			n = -n;
	}
	while (n)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

int		len_long(long n, long base)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0 && base == 10)
	{
		ret++;
		if (n < -999999999999999999)
			return (20);
		else
			n = -n;
	}
	while (n)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

int		len_uint(unsigned int n, unsigned int base)
{
	return (n == 0 ? 1 : (len_uint(n /= base, base) + 1));
}

int		len_ulong(unsigned long n, unsigned long base)
{
	return (n == 0 ? 1 : (len_uint(n /= base, base) + 1));
}

int		len_ull(unsigned long long n, unsigned long long base)
{
	return (n == 0 ? 1 : (len_uint(n /= base, base) + 1));
}
