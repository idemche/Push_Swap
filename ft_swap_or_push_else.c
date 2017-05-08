/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_or_push_else.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:22:14 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:42:42 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_allfree(t_stack *stacks)
{
	t_node *temp;
	t_node *elem;

	if (!(temp = stacks->stack_a->head)
		|| !(elem = stacks->stack_a->head->next))
		return (0);
	while (elem)
	{
		free(temp);
		temp = elem;
		elem = elem->next;
	}
	free(temp);
	free(stacks->stack_b);
	return (1);
}

t_byte		ft_is_sort(t_stack *stacks)
{
	t_node *elem;

	elem = A->head;
	while (elem->next)
	{
		if ((t_i)elem->next->value < (t_i)elem->value)
			return (0);
		elem = elem->next;
	}
	if (!B->elem)
	{
		(stacks->iterator > 0) ? ft_buffer_print(stacks) :
		write(1, "\033[0;32mStack is already sorted:)\033[0m\n", 37);
		exit(ft_allfree(stacks));
	}
	return (1);
}

int			ft_less_than_median(int med, t_dlist *s, int size, char operation)
{
	int		iterator;
	t_node	*element;

	iterator = -1;
	element = s->head;
	while (++iterator < size && element)
	{
		if ((operation && (t_i)element->value <= med)
			|| (!operation && (t_i)element->value > med))
			return (1);
		element = element->next;
	}
	return (0);
}

int			ft_max(t_dlist *s, int len)
{
	t_node			*element;
	t_node			*max;
	int				iterator;

	iterator = -1;
	if (!(element = s->head))
		return (0);
	max = element;
	while (++iterator < len && element)
	{
		if ((t_i)max->value < (t_i)element->value)
			max = element;
		element = element->next;
	}
	return ((int)max->value);
}
