/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:45:21 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:29:22 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_buffer_initialize(t_stack *stacks, short size)
{
	stacks->iterator = 0;
	while (--size >= 0)
		stacks->buffer[size] = 0;
}

void	ft_buffer_print(t_stack *stacks)
{
	ft_check_buffer(stacks);
	write(1, stacks->buffer, stacks->iterator);
	ft_buffer_initialize(stacks, 4096);
}

void	ft_buffer(t_stack *stacks, char *instruction)
{
	__builtin_strcat(stacks->buffer, instruction);
	stacks->iterator += (__builtin_strlen(instruction) == 4) ? 4 : 3;
	if (stacks->iterator >= 4092)
		ft_buffer_print(stacks);
}
