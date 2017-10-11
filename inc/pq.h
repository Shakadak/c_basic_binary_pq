/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 10:58:35 by npineau           #+#    #+#             */
/*   Updated: 2017/10/11 12:16:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PQ_H
# define PQ_H

# include <stddef.h>

typedef int		(*t_pq_cmp)(void*, void*);
typedef void	(*t_pq_free)(void*);

typedef struct	s_pq
{
	void		*elems;
	size_t		capacity;
	size_t		size;
	size_t		used;
	t_pq_cmp	cmp;
	t_pq_free	free;
}				t_pq;

t_pq			pq_new(size_t size, t_pq_cmp cmp, t_pq_free pq_free);
t_pq			*pq_insert(void *pv, t_pq *pq);
int				pq_pop(t_pq *pq, void **out);

#endif
