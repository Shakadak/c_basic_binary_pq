/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 11:51:32 by npineau           #+#    #+#             */
/*   Updated: 2017/10/16 12:49:33 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inc/pq.h"

#define TABSIZE 9

void	unit(void *nada)
{
	(void)nada;
}

int		ord(int *l, int *r)
{
	if (*l < *r)
	{
		return (-1);
	}
	else if (*l == *r)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	print_int_array(int *array, size_t capacity)
{
	size_t	i;

	i = 0;
	while (i < capacity)
	{
		printf("%d", array[i]);
		i += 1;
		if (i < capacity)
		{
			printf(", ");
		}
	}
	printf("\n");
}

int		main(void)
{
	static int	tab[TABSIZE] = {9, 3, 4, 2, 7, 5, 8, 1, 6};
	int			i;
	t_pq		pq;

	i = 0;
	pq = pq_new(sizeof(int), (t_pq_cmp)ord, unit);
	while (i < TABSIZE)
	{
		printf("%d", tab[i]);
		pq_insert(&tab[i], &pq);
		i += 1;
		print_int_array(pq.elems, pq.used);
	}
	print_int_array(pq.elems, pq.used);
	return (0);
}
