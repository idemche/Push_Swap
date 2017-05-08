/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_or_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:42:46 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:42:36 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_a_median(t_dlist *stack, int size)
{
	int *array;
	int median;

	array = (int*)malloc(sizeof(int) * size);
	ft_list_to_array(stack, array, size);
	median = array[size / 2 - 1];
	free(array);
	return (median);
}

void	ft_push_backwards_else(t_stack *stacks, int size)
{
	int l;
	int median;
	int b_len;

	l = 0;
	b_len = size;
	median = ft_find_a_median(B, size);
	while (ft_less_than_median(median, stacks->stack_a, b_len, 0))
	{
		ft_is_sort(stacks);
		if ((t_i)B->head->value > median)
			ft_push(stacks, 'y', 'a');
		else if (++l)
			ft_rotate(stacks, 'y', 'b');
		b_len--;
	}
	if (l && l < B->elem - l && A->elem != size)
		while (l--)
			ft_reverse_rotate(stacks, 'y', 'b');
	else if (l && l >= B->elem - l && A->elem != size)
		while (B->elem - l > 0 && l++)
			ft_rotate(stacks, 'y', 'b');
	ft_swap_or_push(stacks, size - (size / 2));
	ft_push_backwards(stacks, size / 2);
}

void	ft_push_backwards(t_stack *stacks, int size)
{
	ft_is_sort(stacks);
	if (size == 2)
	{
		if (B->elem && (t_i)B->head->value < (t_i)B->head->next->value)
			ft_swap(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
		ft_push(stacks, 'y', 'a');
	}
	else if (size == 3)
		ft_sort_three_stack_b(stacks, B);
	else if (size == 4 &&
		(t_i)A->head->next->next->next->value == ft_max(B, size))
	{
		ft_sort_three_stack_b(stacks, B);
		ft_push(stacks, 'y', 'a');
	}
	else
		ft_push_backwards_else(stacks, size);
}

void	ft_swap_or_push_else(t_stack *stacks, int size)
{
	int l;
	int med;
	int a_len;

	l = 0;
	a_len = size;
	med = ft_find_a_median(stacks->stack_a, size);
	while (ft_less_than_median(med, stacks->stack_a, a_len, 1))
	{
		ft_is_sort(stacks);
		if ((t_i)A->head->value <= med)
			ft_push(stacks, 'y', 'b');
		else if (++l)
			ft_rotate(stacks, 'y', 'a');
		a_len--;
	}
	if (l && l < A->elem - l && A->elem != size)
		while (l--)
			ft_reverse_rotate(stacks, 'y', 'a');
	else if (l && l > A->elem - l && A->elem != size)
		while (A->elem - l > 0 && l++)
			ft_rotate(stacks, 'y', 'a');
	ft_swap_or_push(stacks, size - size / 2);
	ft_push_backwards(stacks, size / 2);
}

void	ft_swap_or_push(t_stack *stacks, int size)
{
	if (ft_is_sort(stacks))
		return ;
	if (size == 2 && (t_i)A->head->value > (t_i)A->head->next->value)
		ft_swap(stacks, 'y', 'a');
	else if (size == 3 && A->elem == size)
		ft_sort_three_elements(stacks, A);
	else if (size == 3 && A->elem > size)
		ft_sort_three_stack_a(stacks, A);
	else if (size == 4 && A->elem > 3
		&& (t_i)A->head->next->next->next->value == ft_max(A, size))
		ft_sort_three_stack_a(stacks, A);
	else if (size >= 4)
		ft_swap_or_push_else(stacks, size);
}
