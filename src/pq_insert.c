/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:18:50 by npineau           #+#    #+#             */
/*   Updated: 2017/10/16 12:46:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/pq.h"

static void	*mmemcpy(void *out, const void *in, size_t len)
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

static void	sift_up(t_pq *pq, size_t c)
{
	size_t			p;
	unsigned char	*elems;

	elems = (unsigned char *)pq->elems;
	while (c > 0)
	{
		p = (c - 1) >> 1;
		if (pq->cmp(elems + pq->size * c, elems + pq->size * p) < 0)
		{
			swap(elems + pq->size * c, elems + pq->size * p, pq->size);
			c = p;
		}
		else
		{
			break ;
		}
	}
}

t_pq		*pq_insert(void *pv, t_pq *pq)
{
	void	*tmp;

	if (pq->used == pq->capacity)
	{
		tmp = malloc(pq->size * (pq->capacity == 0 ? 16 : pq->capacity * 2));
		mmemcpy(tmp, pq->elems, pq->size * pq->used);
		free(pq->elems);
		pq->elems = tmp;
		pq->capacity = pq->capacity == 0 ? 16 : pq->capacity * 2;
	}
	mmemcpy((unsigned char*)pq->elems + pq->used * pq->size, pv, pq->size);
	sift_up(pq, pq->used);
	pq->used += 1;
	return (pq);
}
