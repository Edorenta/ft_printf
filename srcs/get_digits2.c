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

int		len_ll(long long n, uint8_t base)
{
	return (n == 0 ? 1 : (len_ll(n / base, base) + 1));
}

int		uitab_len(unsigned int *s)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		ret += get_nb_bytes(s[i]);
		i++;
	}
	return (ret);
}
