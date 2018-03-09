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

void	pnbr(int nb)
{
	if (nb < 0)
		pchar('-');
	if (nb == -2147483648)
		return (pstr("2147483648"));
	if ((nb = (nb < 0 ? -nb : nb)) >= 10)
		pnbr(nb / 10);
	pchar((nb % 10) + '0');
}

void	pnbr_oct(int n)
{
	int		i;

	i = 0;
	pnbr_base((n & 0xc0000000) >> 30, 8);
	n <<= 2;
	while (i < 10)
	{
		pnbr_base((n & 0xe0000000) >> 29, 8);
		n <<= 3;
		i++;
	}
}

void	plong_oct(long n)
{
	int		i;

	i = 0;
	pnbr_base((n & 0x8000000000000000) >> 63, 8);
	n <<= 1;
	while (i < 21)
	{
		pnbr_base((n & 0xe000000000000000) >> 61, 8);
		n <<= 3;
		i++;
	}
}
