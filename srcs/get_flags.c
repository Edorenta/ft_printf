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

int		eof(char c)
{
	if (c != '#' && c != '0' && c != '-' && c != '+' && c != ' ')
		return (1);
	return (0);
}

void	get_precision(const char *str, t_param *p)
{
	p->flags[11] = str[p->i] == '*' ? va_arg(p->va, int) : ft_atoi(&str[p->i]);
	if (p->flags[11] || str[p->i] == '*')
		p->i += str[p->i] == '*' ? 1 : length_int(p->flags[11], 10);
	if (str[p->i] == '.')
	{
		if (str[p->i + 1] == '*')
		{
			if ((p->flags[12] = va_arg(p->va, int)) == 0)
				p->flags[13] = 1;
			p->i += 2;
		}
		else
		{
			p->i++;
			if (str[p->i] >= '0' && str[p->i] <= '9')
			{
				p->flags[12] = ft_atoi(&str[p->i]);
				if (p->flags[12] == 0)
					p->flags[13] = 1;
				p->i += length_int(p->flags[12], 10);
			}
			else
				p->flags[13] = 1;
		}
	}
}

void	get_padding(const char *str, t_param *p)
{
	if (str[p->i] == '#')
		p->flags[HASH] = 1;
	if (str[p->i] == '0')
		p->flags[ZPAD] = 1;
	if (str[p->i] == '-')
		p->flags[LEFT] = 1;
	if (str[p->i] == '+')
		p->flags[PLUS] = 1;
	if (str[p->i] == ' ')
		p->flags[SPACE] = 1;
	p->i++;
	if (!eof(str[p->i]))
		get_padding(str, p);
	else
		get_precision(str, p);
	if (p->flags[11] < 0)
	{
		p->flags[11] *= -1;
		p->flags[LEFT] = 1;
	}
}

void	get_length(char str[p->i], int *p->flags)
{
	if (str[p->i] == 'z')
		p->flags[_Z_] = 1;
	else if (str[p->i] == 'h')
	{
		if (str[p->i + 1] == 'h')
		{
			p->flags[_HH_] = 1;
			p->i++;
		}
		else
			p->flags[_H_] = 1;
	}
	else if (str[p->i] == 'l')
	{
		if (str[p->i + 1] == 'l')
		{
			p->flags[_LL_] = 1;
			p->i++;
		}
		else
			p->flags[_L_] = 1;
	}
	else
		p->i--;
}

int		is_length_modifier(int p->flags)
{
	return (flags[5] + flags[6] + flags[7] + flags[8] + flags[9] + flags[10]);
}
