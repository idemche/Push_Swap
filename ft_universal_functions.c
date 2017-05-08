/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_universal_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 01:49:50 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:22:22 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_print_it(t_stack *stacks)
{
	write(1, "            [", 13);
	(FLAG.c) ? write(1, "\033[0;33ma\033[0m", 12)
	: write(1, "a", 1);
	write(1, "]         [", 11);
	(FLAG.c) ? write(1, "\033[0;34mb\033[0m", 12)
	: write(1, "b", 1);
	write(1, "]\n", 2);
}

static int		ft_putnbr(int num)
{
	unsigned	num_len;
	unsigned	to_return;
	unsigned	n;

	num_len = 1;
	to_return = 1;
	write(1, "{", 1);
	n = (num < 0 && write(1, "-", 1)) ? -num : num;
	while ((num /= 10) && (num_len *= 10))
		to_return++;
	while (num_len)
		(num = (n / num_len) % 10 + 48) && write(1, &num, 1)
	&& (num_len /= 10);
	write(1, "}", 1);
	return (to_return);
}

static void		ft_spacer(int size)
{
	while (10 - size++ > 0)
		write(1, " ", 1);
}

void			ft_represent(t_stack *stacks, int iter)
{
	t_node *a_b[2];

	a_b[0] = A->head;
	a_b[1] = B->head;
	ft_print_it(stacks);
	while (++iter < stacks->full_size)
	{
		if (write(1, "            ", 12) && iter < (int)A->elem)
		{
			ft_spacer(ft_putnbr((int)a_b[0]->value));
			a_b[0] = a_b[0]->next;
		}
		else
			(FLAG.c) ? write(1, "|\033[0;31m-\033[0m|         ", 24)
		: write(1, "|-|         ", 12);
		if (iter < (int)B->elem)
		{
			ft_putnbr((int)a_b[1]->value);
			a_b[1] = a_b[1]->next;
		}
		else
			(FLAG.c) ? write(1, "|\033[0;31m-\033[0m|", 14)
		: write(1, "|-|", 3);
		write(1, "\n", 2);
	}
}

void			ft_flag_searcher(t_stack *stacks, int argc, char **argv)
{
	stacks->flags.w = 0;
	stacks->flags.s = 0;
	while (argc-- > 0)
	{
		if (!STRCMP(argv[argc], "-w"))
			stacks->flags.w = 1;
		else if (!STRCMP(argv[argc], "-s"))
			stacks->flags.s = 1;
		else if (!STRCMP(argv[argc], "-c"))
			stacks->flags.c = 1;
	}
}
