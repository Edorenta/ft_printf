/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:10:35 by pde-rent          #+#    #+#             */
/*   Updated: 2017/05/17 09:17:59 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

void	*ft_safe_calloc(size_t count, size_t size)
{
	void	*const mem = malloc(count * size);

	if (mem == (void *)0)
		ft_exit("ft_safe_calloc", "Out of memory (Malloc failed)");
	ft_bzero(mem, count * size);
	return (mem);
}
