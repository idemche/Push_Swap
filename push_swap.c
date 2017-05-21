/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:27:16 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/21 19:22:29 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** You may switch ft_swap_or_push(t_stack*, size of stack)
** onto ft_push_or_swap(t_stack*, starting element). An algorithm is more
** on minor parameters but it won't handle > 100 elements as ft_swap_or_push
*/

void	ft_instant_check(t_stack *stacks)
{
	if ((t_i)A->head->value > (t_i)A->head->next->value)
		ft_reverse_rotate(stacks, 'y', 'a');
}

int		main(int argc, char *argv[])
{
	t_stack	stacks;

	stacks.flags.is_checker = 0;
	ft_buffer_initialize(&stacks, 4096);
	ft_createlists(&stacks);
	if (argc < 1 || (!stacks.stack_a || !stacks.stack_b))
		exit(write(2, "Error\n", 6));
	else if (argc < 2)
		return (write(1, "\033[0;31mNothing to sort\033[0m\n", 27));
	ft_flag_searcher(&stacks, argc, argv);
	ft_apply_flags(&stacks, argc, argv);
	stacks.full_size = stacks.stack_a->elem;
	if (stacks.full_size == 1)
		exit(write(1, "\033[0;31mOnly one element to chum:(\033[0m\n", 38));
	ft_instant_check(&stacks);
	(stacks.flags.a) ? ft_push_or_swap(&stacks, stacks.stack_a->head)
	: ft_swap_or_push(&stacks, stacks.full_size);
	(stacks.iterator > 0) ? ft_buffer_print(&stacks) :
	write(1, "\033[0;32mStack is already sorted:)\033[0m\n", 37);
	return (ft_allfree(&stacks));
}
