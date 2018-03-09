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

bool        is_digit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

size_t      slen(const char *str)
{
	return ((*str) ? slen(++str) + 1 : 0);
}

void        pchar(const char c)
{
	write(1, &c, 1);
}

void        pstr(const char *str)
{
	write(1, str, slen(str));
}