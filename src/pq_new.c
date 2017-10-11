/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:01:44 by npineau           #+#    #+#             */
/*   Updated: 2017/10/11 12:07:48 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/pq.h"

t_pq	pq_new(size_t size, t_pq_cmp cmp)
{
	t_pq	pq;

	pq.elems = malloc(size * 16);
	pq.capacity = 16;
	pq.used = 0;
	pq.size = size;
	pq.cmp = cmp;

	return pq;
}
