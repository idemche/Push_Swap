/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:45:07 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:28:28 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_list_push_top(t_dlist *list, void *data)
{
	t_node *tmp;

	if (!(tmp = (t_node*)malloc(sizeof(t_node))))
		exit(write(2, "Malloc Error\n", 13));
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
		list->head->prev = tmp;
	list->head = tmp;
	if (list->tail == NULL)
		list->tail = tmp;
	list->elem++;
	list->argc++;
}

void		ft_list_push_back(t_dlist *list, void *data)
{
	t_node *tmp;

	if (!(tmp = (t_node*)malloc(sizeof(t_node))))
		exit(write(2, "Malloc Error\n", 13));
	tmp->value = data;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
	list->elem++;
	list->argc++;
}

void		ft_createlists(t_stack *stack)
{
	if (!(stack->stack_a = (t_dlist*)malloc(sizeof(t_dlist))) ||
		!(stack->stack_b = (t_dlist*)malloc(sizeof(t_dlist))))
		exit(write(2, "Malloc Error\n", 13));
	if (stack->stack_a && stack->stack_b)
	{
		stack->stack_a->elem = 0;
		stack->stack_b->elem = 0;
		stack->stack_a->argc = 0;
		stack->stack_b->argc = 0;
		stack->stack_a->head = NULL;
		stack->stack_b->head = NULL;
		stack->stack_a->tail = NULL;
		stack->stack_b->tail = NULL;
	}
}

void		ft_duplicate_searcher(t_dlist *stack, void *data)
{
	t_node	*element;

	if (stack)
	{
		element = stack->head;
		while (element)
		{
			if (element->value == data)
				exit(write(2, "\033[0;31mDuplicate number\033[0m\n", 29));
			element = element->next;
		}
	}
}
