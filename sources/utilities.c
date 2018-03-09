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

int		ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	while ((*str == 32) || (*str > 8 && *str < 14))
		str++;
	sign = ((*str == '-') ? -1 : 1);
	if ((*str == '-') || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 - (*str++ - '0');
	return (sign * (-res));
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char*)s;
	while (n--)
	{
		*str = '\0';
		str++;
	}
}
