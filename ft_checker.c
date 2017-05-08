/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 21:30:03 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:42:51 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_initializers(t_instructions *inst)
{
	inst->instruction[0] = "sa";
	inst->operation[0] = &ft_swap;
	inst->instruction[1] = "sb";
	inst->operation[1] = &ft_swap;
	inst->instruction[2] = "ss";
	inst->operation[2] = &ft_swap;
	inst->instruction[3] = "pa";
	inst->operation[3] = &ft_push;
	inst->instruction[4] = "pb";
	inst->operation[4] = &ft_push;
	inst->instruction[5] = "ra";
	inst->operation[5] = &ft_rotate;
	inst->instruction[6] = "rb";
	inst->operation[6] = &ft_rotate;
	inst->instruction[7] = "rr";
	inst->operation[7] = &ft_rotate;
	inst->instruction[8] = "rra";
	inst->operation[8] = &ft_reverse_rotate;
	inst->instruction[9] = "rrb";
	inst->operation[9] = &ft_reverse_rotate;
	inst->instruction[10] = "rrr";
	inst->operation[10] = &ft_reverse_rotate;
}

static t_byte	ft_is_sort_checker(t_dlist *stack)
{
	t_node *elem;

	elem = stack->head;
	while (elem->next)
	{
		if ((t_i)elem->next->value < (t_i)elem->value)
			return (0);
		elem = elem->next;
	}
	return (1);
}

static void		ft_apply(t_stack *stacks, t_instructions *inst, char *line)
{
	short iterator;

	iterator = -1;
	while (++iterator <= 10
		&& STRCMP(inst->instruction[iterator], line))
		;
	if (iterator <= 10)
	{
		inst->operation[iterator](stacks, 'n',
			(iterator < 8) ? (inst->instruction[iterator])[1]
			: (inst->instruction[iterator])[2]);
	}
	else
		exit(write(1, "\033[0;31mWrong Command\033[0m\n", 25));
}

static t_byte	ft_read_and_check(t_stack *stacks, t_instructions *inst)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		ft_apply(stacks, inst, line);
		(stacks->flags.w) ? ft_represent(stacks, write(1, "\n", 1) - 2) : 0;
		free(line);
	}
	free(line);
	return (ft_is_sort_checker(A) ? write(1, "\033[0;32mOK\033[0m\n", 14)
						: write(1, "\033[0;31mKO\033[0m\n", 14));
}

int				main(int argc, char **argv)
{
	t_stack			stacks;
	t_instructions	instructions;

	stacks.flags.is_checker = 1;
	ft_buffer_initialize(&stacks, 4096);
	ft_createlists(&stacks);
	ft_initializers(&instructions);
	if (argc < 1 || (!stacks.stack_a || !stacks.stack_b))
		exit(write(2, "Error\n", 6));
	else if (argc < 2)
		return (write(1, "\033[0;31mNothing to check\033[0m\n", 28));
	ft_flag_searcher(&stacks, argc, argv);
	ft_apply_flags(&stacks, argc, argv);
	if (stacks.stack_a->elem == 1)
		exit(write(1, "\033[0;31mOnly one element to chum:(\033[0m\n", 38));
	stacks.full_size = stacks.stack_a->elem;
	return (ft_read_and_check(&stacks, &instructions));
}
