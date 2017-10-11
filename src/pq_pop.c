/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:37:11 by npineau           #+#    #+#             */
/*   Updated: 2017/10/11 13:58:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/pq.h"

static void	*mmemcpy(const void *in, void *out, size_t len)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				i;

	i = 0;
	source = in;
	destination = out;
	while (i < len)
	{
		destination[i] = source[i];
		i += 1;
	}
	return (out);
}

static void	swap(void *l, void *r, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	c;
	size_t			i;

	i = 0;
	a = l;
	b = r;
	while (i < len)
	{
		c = a[i];
		a[i] = b[i];
		b[i] = c;
		i += 1;
	}
}

int			pq_pop(t_pq *pq, void **out)
{
	return (1);
}
