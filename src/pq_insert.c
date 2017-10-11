/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:18:50 by npineau           #+#    #+#             */
/*   Updated: 2017/10/11 13:45:47 by npineau          ###   ########.fr       */
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

static void	siftUp(t_pq *pq, size_t c)
{
	size_t			p;
	unsigned char	*elems;

	if (c > 0)
	{
		elems = (unsigned char *)pq->elems;
		p = (c - 1) >> 1;
		if (pq->cmp(elems + pq->size * c, elems + pq->size * p) < 0)
		{
			swap(elems + pq->size * c, elems + pq->size * p, pq->size);
			siftUp(pq, p);
		}
	}
}


t_pq	*pq_insert(void *pv, t_pq *pq)
{
	void	*tmp;

	if (pq->used == pq->capacity)
	{
		tmp = malloc(pq->size * pq->capacity * 2);
		mmemcpy(tmp, pq->elems, pq->size * pq->capacity);
		free(pq->elems);
		pq->elems = tmp;
		pq->capacity *= 2;
	}
	pq->used += 1;
	mmemcpy((unsigned char*)pq->elems + pq->used * pq->size, pv, pq->size);
	siftUp(pq, pq->used - 1);
	return (pq);
}
