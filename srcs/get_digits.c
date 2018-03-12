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

int		len_int(int n, uint8_t base)
{
	if (n < -999999999 || n > 999999999)
		return (11);
	return (n == 0 ? 1 : (1 + (len_int((n / base), base))));
}

int		len_long(long n, uint8_t base)
{
	if (n < -999999999999999999 || n > 999999999999999999)
		return (20);
	return (n == 0 ? 1 : (1 + (len_long((n / base), base))));
}

int		len_uint(unsigned int n, uint8_t base)
{
	return (n == 0 ? 1 : (1 + (len_uint((n / base), base))));
}

int		len_ulong(unsigned long n, uint8_t base)
{
	return (n == 0 ? 1 : (1 + (len_ulong((n / base), base))));
}

int		len_ull(unsigned long long n, uint8_t base)
{
	return (n == 0 ? 1 : (1 + (len_ull((n / base), base))));
}
