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

void	get_precision(const char *str, t_param *p)
{
	p->padding = str[p->i] == '*' ? va_arg(p->va, int) : ft_atoi(&str[p->i]);
	if (p->padding || str[p->i] == '*')
		p->i += str[p->i] == '*' ? 1 : len_int(p->padding, 10);
	if (str[p->i] == '.')
	{
		if (str[p->i + 1] == '*' && (p->i += 2))
			(p->precision = va_arg(p->va, int));
		else
		{
			p->i++;
			if (is_digit(str[p->i]) && (p->precision = ft_atoi(&str[p->i])))
				p->i += len_int(p->precision, 10);
		}
	}
	if (p->padding < 0)
	{
		p->padding = - p->padding;
		p->flags[LEFT] = true;
	}
	if (p->flags[NODIGIT])
		p->flags[NODIGIT] = true;
}

void	get_padding(const char *str, t_param *p)
{
	while (str[p->i])
	{
		if (str[p->i] == '#')
			p->flags[HASH] = true;
		else if (str[p->i] == '0')
			p->flags[ZPAD] = true;
		else if (str[p->i] == '-')
			p->flags[LEFT] = true;
		else if (str[p->i] == '+')
			p->flags[PLUS] = true;
		else if (str[p->i] == ' ')
			p->flags[SPACE] = true;
		else
			break;
		p->i++;
	}
}

void	get_len(const char *str, t_param *p)
{
	if (str[p->i] == 'j')
		(p->flags)[_J_] = true;
	else if (str[p->i] == 'z')
		p->flags[_Z_] = true;
	else if (str[p->i] == 'h')
	{
		if (str[p->i + 1] == 'h' && (p->flags[_HH_] = true))
			p->i++;
		else
			 (p->flags[_H_] = true);
	}
	else if (str[p->i] == 'l')
	{
		if (str[p->i + 1] == 'l' && (p->flags[_LL_] = true))
			p->i++;
		else
			 (p->flags[_L_] = true);
	}
	else
		p->i--;		
}

bool		is_len_mod(t_param *p)
{
	if ((p->flags[_H_] || p->flags[_HH_]
			|| p->flags[_L_] || p->flags[_LL_]
			|| p->flags[_J_] || p->flags[_Z_]))
		return (true);
	return (false);
}
