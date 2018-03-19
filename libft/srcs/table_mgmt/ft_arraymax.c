/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:29:50 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/23 18:08:19 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_arraymax(int *tab, int n)
{
	int	i;
	int	max;

	if (!tab)
		return (0);
	i = -1;
	max = tab[0];
	while (++i < n)
		if (tab[i] > max)
			max = tab[i];
	return (max);
}