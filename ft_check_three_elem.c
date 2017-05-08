/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_three_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:56:43 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/05 06:16:41 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_elements(t_stack *stacks, t_dlist *a)
{
	while (!(SA0 < SA1 && SA1 < SA2))
	{
		ft_is_sort(stacks);
		if (SA0 < SA1 && SA1 > SA2 && SA0 > SA2)
			ft_reverse_rotate(stacks, 'y', 'a');
		else if (SA0 < SA1 && SA1 > SA2 && SA0 < SA2)
		{
			ft_swap(stacks, 'y', 'a');
			ft_rotate(stacks, 'y', 'a');
		}
		else if (SA0 > SA1 && SA0 > SA2 && SA1 > SA2)
		{
			ft_swap(stacks, 'y', 'a');
			ft_reverse_rotate(stacks, 'y', 'a');
		}
		else if (SA0 > SA1 && SA0 > SA2 && SA1 < SA2)
			ft_rotate(stacks, 'y', 'a');
		else if (SA0 > SA1 && SA1 < SA2 && SA0 < SA2)
			ft_swap(stacks, 'y', 'a');
	}
}

void	ft_sort_three_stack_a(t_stack *stacks, t_dlist *a)
{
	while (!(SA0 < SA1 && SA1 < SA2))
	{
		ft_is_sort(stacks);
		if (SA0 < SA1 && SA1 > SA2)
		{
			ft_rotate(stacks, 'y', 'a');
			ft_swap(stacks, 'y', 'a');
			ft_reverse_rotate(stacks, 'y', 'a');
			if (SA0 > SA1)
				ft_swap(stacks, 'y', 'a');
		}
		else if (SA0 > SA1 && SA0 > SA2)
		{
			ft_swap(stacks, 'y', 'a');
			ft_rotate(stacks, 'y', 'a');
			ft_swap(stacks, 'y', 'a');
			ft_reverse_rotate(stacks, 'y', 'a');
			if (SA0 > SA1)
				ft_swap(stacks, 'y', 'a');
		}
		else if (SA0 > SA1 && SA1 < SA2 && SA0 < SA2)
			ft_swap(stacks, 'y', 'a');
	}
}

void	ft_sort_three_stack_b(t_stack *stacks, t_dlist *b)
{
	if (SB0 < SB1 && SB1 > SB2)
	{
		ft_swap(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
		if (SB0 < SB1)
			ft_swap(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
		ft_push(stacks, 'y', 'a');
	}
	else if (SB0 > SB1 && SB0 > SB2)
	{
		ft_push(stacks, 'y', 'a');
		if (SB0 < SB1)
			ft_swap(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
		ft_push(stacks, 'y', 'a');
	}
	else
		ft_sort_three_stack_b_else(stacks, b);
}

void	ft_sort_three_stack_b_else(t_stack *stacks, t_dlist *b)
{
	if (SB0 > SB1 && SB1 < SB2 && SB0 < SB2)
	{
		ft_rotate(stacks, 'y', 'b');
		ft_rotate(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
		ft_reverse_rotate(stacks, 'y', 'b');
		ft_reverse_rotate(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
		ft_push(stacks, 'y', 'a');
	}
	else if (SB1 > SB0 && SB2 > SB1)
	{
		ft_rotate(stacks, 'y', 'b');
		ft_swap(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
		ft_push(stacks, 'y', 'a');
		ft_reverse_rotate(stacks, 'y', 'b');
		ft_push(stacks, 'y', 'a');
	}
}
