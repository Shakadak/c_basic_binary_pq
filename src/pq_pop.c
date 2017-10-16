/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:37:11 by npineau           #+#    #+#             */
/*   Updated: 2017/10/16 10:15:29 by npineau          ###   ########.fr       */
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

static void	sift_down(t_pq *pq, size_t parent)
{
	size_t			child;
	size_t			left;
	size_t			right;
	unsigned char	*elems;

	elems = (unsigned char *)pq->elems;
	while (parent < pq->used)
	{
		left = (parent << 1) + 1;
		right = left + 1;
		child = parent;
		if (left < pq->used)
			if (pq->cmp(elems + pq->size * left,
						elems + pq->size * parent) < 0)
				child = left;
		if (right < pq->used)
			if (pq->cmp(elems + pq->size * right,
						elems + pq->size * parent) < 0)
				child = right;
		if (child == parent)
			break ;
		swap(elems + pq->size * child, elems + pq->size * parent, pq->size);
		parent = child;
	}
}

int			pq_pop(t_pq *pq, void **out)
{
	void	*tmp;

	if (pq->used == 0)
	{
		return (0);
	}
	mmemcpy(*out, (unsigned char*)pq->elems, pq->size);
	pq->used -= 1;
	mmemcpy((unsigned char*)pq->elems,
			(unsigned char*)pq->elems + pq->used * pq->size, pq->size);
	sift_down(pq, 0);
	if (pq->used < pq->capacity / 4 && pq->capacity / 2 > 16)
	{
		tmp = malloc(pq->size * pq->capacity / 2);
		mmemcpy(tmp, pq->elems, pq->size * pq->used);
		free(pq->elems);
		pq->elems = tmp;
		pq->capacity /= 2;
	}
	return (1);
}
