/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:31:13 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:42:27 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_ends(t_node *last, t_node *first)
{
	while (first)
	{
		if ((t_i)last->value > (t_i)first->value)
			return (0);
		first = first->next;
		last = last->next;
	}
	return (1);
}

int		ft_check_backward_ends(t_node *last, t_node *first)
{
	while (first)
	{
		if ((t_i)last->value < (t_i)first->value)
			return (0);
		first = first->next;
		last = last->next;
	}
	return (1);
}

int		ft_check_stack_tail(t_stack *stacks)
{
	ft_reverse_rotate(stacks, 'y', 'a');
	if (ft_check_ends(A->head, A->NNODE))
		return (1);
	ft_reverse_rotate(stacks, 'y', 'a');
	ft_swap(stacks, 'y', 'a');
	ft_rotate(stacks, 'y', 'a');
	ft_rotate(stacks, 'y', 'a');
	return (ft_check_ends(A->head, A->NNODE) ? 1 : 0);
}

int		ft_check_stack_start(t_stack *stacks, t_node *first,
	t_node *last)
{
	if (A->argc > 3 && (t_i)A->head->value < (t_i)A->NNODE->value
		&& (t_i)A->head->value < (t_i)A->tail->value
		&& (t_i)A->NNODE->value > (t_i)A->tail->value)
	{
		if (!ft_check_ends(A->head, A->NNODE))
			return (0);
	}
	while (first)
	{
		if (first == A->NNODE && (t_i)last->value > (t_i)first->value)
		{
			ft_swap(stacks, 'y', 'a');
			if (ft_check_ends(A->head, A->NNODE))
				return (1);
		}
		if (first == A->tail && (t_i)first->value < (t_i)last->value
			&& A->argc > 3 && ft_check_stack_tail(stacks) == 1)
			return (1);
		else if ((t_i)first->value < (t_i)last->value)
			return (0);
		first = first->next;
		last = last->next;
	}
	return (ft_check_ends(A->head, A->NNODE) ? 0 : 1);
}

int		ft_check_stack_end(t_stack *stacks)
{
	if (!ft_check_ends(A->head, A->NNODE))
		return (0);
	if (B->head && B->NNODE && ft_check_backward_ends(B->head, B->NNODE))
	{
		while (B->head)
			ft_push(stacks, 'y', 'a');
		if (!B->head)
			return (1);
	}
	else
	{
		ft_push(stacks, 'y', 'a');
		return (1);
	}
	return (0);
}
