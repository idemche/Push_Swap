/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 00:00:32 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:36:59 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_xor_swap(void **one, void **two)
{
	if (*one == *two)
		return ;
	*one += (int)*two;
	*two = *one - (int)*two;
	*one -= (int)*two;
}

void	ft_rotator(t_dlist *stack)
{
	t_node *element;

	element = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	element->next = NULL;
	stack->tail->next = element;
	stack->tail = element;
}

void	ft_reverse_rotator(t_dlist *stack)
{
	t_node *element;

	element = stack->head;
	while (element->next != stack->tail)
		element = element->next;
	element->next->next = stack->head;
	stack->head = element->next;
	element->next = NULL;
	stack->tail = element;
}
