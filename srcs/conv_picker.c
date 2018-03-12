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

void	fmt_handle(const char *str, t_param *p)
{
	const char	*conv = "sSpdDioOuUxXcCb";
	int			i;

	i = 0;
	while (i < 15)
	{
		if (str[p->i] == conv[i])
		{
			p->j += p->basic_conv[i].ptr(p);
			return ;
		}
		i++;
	}
	if (str[p->i] == '%')
		(p->j) += print_pct(p);
	else
	{
		p->i--;
		p->j += print_spaces(p);
	}
}

void	fmt_mods(const char *str, t_param *p)
{
	const	char	*conv = "diouxX";;
	int				i;

	i = 0;
	while (i < 36) 
	{
		if (str[p->i] == conv[i % 6] && p->flags[i / 6 + 5])
		{
			p->j += p->adv_conv[i].ptr(p);
			return ;
		}
		i++;
	}
	if (str[p->i] == '%')
		p->j += print_pct(p);
	else
	{
		p->i--;
		p->j += print_spaces(p);
	}
}
