/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:24:02 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:33:16 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	xor_swap(int *a, int *b)
{
	if (a == b)
		return (0);
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return (1);
}

static int	partition(int *array, int left, int right)
{
	int	pivot;
	int	one;
	int	two;

	one =
	two = left - 1;
	pivot = array[right];
	while (++two < right)
		if (array[two] <= pivot)
			xor_swap(&(array[++one]), &array[two]);
	xor_swap(&(array[one + 1]), &array[right]);
	return (one + 1);
}

static void	quicksort(int *array, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right);
		quicksort(array, left, pivot - 1);
		quicksort(array, pivot + 1, right);
	}
}

void		ft_list_to_array(t_dlist *stack, int array[], int size)
{
	t_node	*elem;
	int		counter;
	int		sort;

	elem = stack->head;
	counter = 0;
	sort = size - 1;
	while (elem && --size >= 0)
	{
		array[counter++] = (int)elem->value;
		elem = elem->next;
	}
	quicksort(array, 0, sort);
}
