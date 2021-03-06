/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:59:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/19 18:51:31 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"

int		ft_isnan(double x)
{
	t_ieee754 addr;

	addr.f = x;
	return ((unsigned)(addr.u >> 32) & 0x7fffffff) +
	((unsigned)addr.u != 0) > 0x7ff00000;
}
