/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_it_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 01:10:22 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/21 19:25:11 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_argument_hoover(t_stack *stacks, char *str)
{
	long digit;
	char *arg;

	arg = str;
	while (*arg)
	{
		ft_duplicate_searcher(A, (void*)(digit = ft_multiatoi(&arg)));
		stacks->flags.s ? ft_list_push_back(stacks->stack_a, (void*)digit) :
		ft_list_push_top(stacks->stack_a, (void*)digit);
	}
}

static void	ft_fill_from_file(t_stack *stacks, char *file)
{
	char	*arguments;
	char	*line;
	int		fd;
	int		iter;

	iter = -1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		arguments = line;
		ft_argument_hoover(stacks, line);
		free(line);
	}
	free(line);
}

static void	ft_read_from_file(t_stack *stacks, char *file)
{
	int		fd;
	int		length;
	int		read_size;
	char	buffer[BUFF_SIZE + 1];

	fd = open(file, O_RDONLY);
	length = 0;
	while ((read_size = read(fd, buffer, BUFF_SIZE)) > 0)
		length += read_size;
	if (fd < 0)
		exit(write(2, "\033[0;31mTHERE IS NO SUCH FILE\033[0m\n", 33));
	else if (length < 1)
		exit(write(2, "\033[0;31mERROR - EMPTY FILE\033[0m\n", 30));
	close(fd);
	ft_fill_from_file(stacks, file);
}

static void	ft_search_and_fill(t_stack *stacks, int argc, char **argv)
{
	while (argc-- > 1)
	{
		if ((stacks->flags.s && !STRCMP(argv[argc], "-s"))
			|| (stacks->flags.w && !STRCMP(argv[argc], "-w"))
			|| (stacks->flags.c && !STRCMP(argv[argc], "-c"))
			|| (stacks->flags.a && !STRCMP(argv[argc], "-a")))
			continue ;
		ft_argument_hoover(stacks, argv[argc]);
	}
}

void		ft_apply_flags(t_stack *stacks, int argc, char **argv)
{
	if (stacks->flags.s)
		while (argc-- > 1)
		{
			if ((stacks->flags.s && !STRCMP(argv[argc], "-s"))
			|| (stacks->flags.w && !STRCMP(argv[argc], "-w"))
			|| (stacks->flags.c && !STRCMP(argv[argc], "-c"))
			|| (stacks->flags.a && !STRCMP(argv[argc], "-a")))
				continue ;
			ft_read_from_file(stacks, argv[argc]);
		}
	else
		ft_search_and_fill(stacks, argc, argv);
}
