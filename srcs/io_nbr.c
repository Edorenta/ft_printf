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

void	pnbr(int n)
{
	if (n < 0)
		pchar('-');
	if ((n = (n < 0 ? -n : n)) >= 10)
		pnbr(n / 10);
	pchar((n % 10) + '0');
}

void	pnbr_oct(int n)
{
	pnbr_base(n, 8);
}

void	plong_oct(long n)
{
	plong_base(n, 8);
}
