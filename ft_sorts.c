/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:48:41 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:26:35 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stacks, char rec, char instruction)
{
	if (instruction == 'a' && !(A->head == NULL || A->NNODE == NULL
			|| A->head->value == A->NNODE->value))
	{
		ft_xor_swap(&A->head->value, &A->NNODE->value);
		(rec == 'y') ? ft_buffer(stacks, "sa\n") : 0;
	}
	else if (instruction == 'b' && !(B->head == NULL || B->NNODE == NULL
		|| B->head->value == B->NNODE->value))
	{
		ft_xor_swap(&B->head->value, &B->NNODE->value);
		(rec == 'y') ? ft_buffer(stacks, "sb\n") : 0;
	}
	else if (instruction == 's')
	{
		ft_swap(stacks, 'n', 'a');
		ft_swap(stacks, 'n', 'b');
		(rec == 'y') ? ft_buffer(stacks, "ss\n") : 0;
	}
	return ;
}

void	ft_push(t_stack *stacks, char rec, char instruction)
{
	if (instruction == 'a' && B->head)
	{
		ft_list_push_top(A, B->head->value);
		ft_pop_top(B);
		(rec == 'y') ? ft_buffer(stacks, "pa\n") : 0;
	}
	else if (instruction == 'b' && A->head)
	{
		ft_list_push_top(B, A->head->value);
		ft_pop_top(A);
		(rec == 'y') ? ft_buffer(stacks, "pb\n") : 0;
	}
	return ;
}

void	ft_rotate(t_stack *stacks, char rec, char instruction)
{
	if (instruction == 'a' && A->head && (A->head != A->tail))
	{
		ft_rotator(A);
		(rec == 'y') ? ft_buffer(stacks, "ra\n") : 0;
	}
	else if (instruction == 'b' && (B->head) && (B->head != B->tail))
	{
		ft_rotator(B);
		(rec == 'y') ? ft_buffer(stacks, "rb\n") : 0;
	}
	else if (instruction == 'r')
	{
		ft_rotate(stacks, 'n', 'a');
		ft_rotate(stacks, 'n', 'b');
		ft_buffer(stacks, "rr\n");
	}
	return ;
}

void	ft_reverse_rotate(t_stack *stacks, char rec, char instruction)
{
	if (instruction == 'a' && A->head && (A->head != A->tail))
	{
		ft_reverse_rotator(A);
		(rec == 'y') ? ft_buffer(stacks, "rra\n") : 0;
	}
	else if (instruction == 'b' && B->head && (B->head != B->tail))
	{
		ft_reverse_rotator(B);
		(rec == 'y') ? ft_buffer(stacks, "rrb\n") : 0;
	}
	else if (instruction == 'r')
	{
		ft_reverse_rotate(stacks, 'n', 'a');
		ft_reverse_rotate(stacks, 'n', 'b');
		ft_buffer(stacks, "rrr\n");
	}
	return ;
}
