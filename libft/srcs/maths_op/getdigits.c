/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdigits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:10:27 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#ifndef STDINT_H
# include <stdint.h>
#endif

int		ft_idigits(int x, uint8_t b)
{
	return (x < b ? 0 : (1 + (ft_idigits((x / (int)b), b))));
}

int		ft_ldigits(long x, uint8_t b)
{
	return (x < b ? 0 : (1 + (ft_ldigits((x / (long)b), b))));
}

int		ft_lldigits(long long x, uint8_t b)
{
	return (x < b ? 0 : (1 + (ft_lldigits((x / (long long)b), b))));
}

int		ft_ddigits(double x, uint8_t b)
{
	return (x < b ? 0 : (1 + (ft_ddigits((x / (double)b), b))));
}

int		ft_decimals(double x, uint8_t b)
{
	int i;

	i = 0;
	x = ft_dabs(x);
	x -= (long long)(x);
	while (ft_dabs(x) >= 0.00001)
	{
		x *= (double)b;
		x -= (long long)(x);
		i++;
	}
	return (i);
}
