/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:00:27 by npineau           #+#    #+#             */
/*   Updated: 2017/10/16 10:16:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/pq.h"

void	destroy(t_pq *pq)
{
	size_t			i;
	unsigned char	*elems;

	i = 0;
	elems = pq->elems;
	while (i < pq->used)
	{
		pq->free(elems + pq->size * i);
		i += 1;
	}
	free(pq->elems);
	pq->elems = NULL;
	pq->used = 0;
	pq->capacity = 0;
}
