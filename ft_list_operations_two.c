/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_operations_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:40:13 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:31:57 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pop_top(t_dlist *list)
{
	t_node	*prev;

	if ((prev = list->head) == NULL)
		exit(write(2, "Stack is empty:)\n", 17));
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	if (prev == list->tail)
		list->tail = NULL;
	free(prev);
	list->elem--;
}

void	ft_pop_back(t_dlist *list)
{
	t_node	*next;

	if ((next = list->tail) == NULL)
		exit(write(2, "Stack is empty:)\n", 17));
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	if (next == list->head)
		list->head = NULL;
	free(next);
	list->elem--;
}
