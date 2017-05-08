/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_or_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:23:16 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:42:18 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_find_minimal(t_node *node)
{
	t_node *min_node;

	min_node = node;
	while (node)
	{
		if ((t_i)node->value < (t_i)min_node->value)
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

int			ft_rotation_finder(t_node *node, t_node *max)
{
	int to_rotate;
	int length;

	to_rotate = 0;
	length = 0;
	while (node)
	{
		(node == max) ? to_rotate = length : 0;
		length++;
		node = node->next;
	}
	return ((length / 2 < to_rotate) ? 0 : 1);
}

void		ft_push_or_swap(t_stack *stacks, t_node *current)
{
	t_node *min;

	if (ft_check_stack_start(stacks, A->NNODE, A->head))
		return ;
	while (current)
	{
		min = ft_find_minimal(A->head);
		while (min != A->head)
		{
			if (ft_rotation_finder(A->head, min))
				ft_rotate(stacks, 'y', 'a');
			else
				ft_reverse_rotate(stacks, 'y', 'a');
		}
		if (ft_check_stack_end(stacks))
			return ;
		ft_push(stacks, 'y', 'b');
		current = A->head;
	}
	current = B->head;
	while (current)
	{
		current = current->next;
		ft_push(stacks, 'y', 'a');
	}
}
