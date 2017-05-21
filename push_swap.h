/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:05:05 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/21 19:15:42 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# define A				stacks->stack_a
# define B				stacks->stack_b
# define NNODE			head->next
# define TNODE			tail->next
# define STRCMP(x, y)	__builtin_strcmp(x, y)
# define SPACED(x)		(x == ' ' || x == '\r')
# define TABBED(x)		(x == '\t' || x == '\v' || x == '\f' || x == '\n')
# define DIGIT(x)		(x >= 48 && x <= 57)
# define FLAG			stacks->flags
# define SA0			(int)a->head->value
# define SA1			(int)a->head->next->value
# define SA2			(int)a->head->next->next->value
# define SB0			(int)b->head->value
# define SB1			(int)b->head->next->value
# define SB2			(int)b->head->next->next->value

typedef int				t_i;
typedef unsigned char	t_byte;
typedef struct	s_node
{
	void			*value;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef	struct	s_flags
{
	int w : 3;
	int s : 3;
	int c : 3;
	int a : 3;
	int is_checker : 3;
}				t_flags;

typedef struct	s_dlist
{
	int		elem;
	int		argc;
	t_node	*head;
	t_node	*tail;
}				t_dlist;

typedef struct	s_stack
{
	int				iterator;
	int				full_size;
	char			buffer[4096];
	char			**argv;
	t_flags			flags;
	t_dlist			*stack_a;
	t_dlist			*stack_b;
}				t_stack;

typedef struct	s_instructions
{
	void	(*operation[11])(t_stack*, char, char);
	char	*instruction[11];
}				t_instructions;

/*
**		Readers
*/

void			ft_apply_flags(t_stack *stacks, int argc, char **argv);

/*
**		Brute	Algorithm
*/

int				ft_find_a_median(t_dlist *stack, int size);
int				ft_less_than_median(int med, t_dlist *s, int size, char flag);
void			ft_push_backwards_else(t_stack *stacks, int size);
void			ft_push_backwards(t_stack *stacks, int size);
void			ft_swap_or_push(t_stack *stacks, int size);
void			ft_swap_or_push_else(t_stack *stacks, int size);

/*
**		Brute	Algorithm
*/

void			ft_sort_three_stack_b(t_stack *stacks, t_dlist *b);
void			ft_sort_three_stack_b_else(t_stack *stacks, t_dlist *b);
void			ft_sort_three_stack_a(t_stack *stacks, t_dlist *a);
void			ft_sort_three_elements(t_stack *stacks, t_dlist *a);

/*
**		Deprecated Algorithm
*/

t_node			*ft_find_minimal(t_node *node);
int				ft_rotation_finder(t_node *node, t_node *max);
void			ft_push_or_swap(t_stack *stacks, t_node *current);
int				ft_check_stack_start(t_stack *stacks, t_node *first,
	t_node *last);
int				ft_check_stack_tail(t_stack *stacks);
int				ft_check_backward_ends(t_node *first, t_node *last);
int				ft_check_ends(t_node *first, t_node *last);
int				ft_check_stack_end(t_stack *stacks);

/*
**		Buffer_operations
*/

void			ft_buffer_initialize(t_stack *stacks, short size);
void			ft_buffer_print(t_stack *stacks);
void			ft_buffer(t_stack *stacks, char *instruction);

/*
**		List_operations
*/

void			ft_list_push_top(t_dlist *list, void *data);
void			ft_list_push_back(t_dlist *list, void *data);
void			ft_pop_top(t_dlist *list);
void			ft_pop_back(t_dlist *list);
void			ft_createlists(t_stack *stack);
void			ft_duplicate_searcher(t_dlist *stack, void *data);
int				ft_allfree(t_stack *stacks);

/*
**		Libft_Functions
*/

int				ps_ft_atoi(char *str);
int				ft_multiatoi(char **str);
unsigned		ps_ft_strlen(char *str);
char			*ps_ft_strcat(char *dst, char *src);
void			ft_xor_swap(void **one, void **two);
void			ft_rotator(t_dlist *stack);
void			ft_reverse_rotator(t_dlist *stack);

/*
**		Operations
*/

void			ft_swap(t_stack *stacks, char rec, char instruction);
void			ft_push(t_stack *stacks, char rec, char instruction);
void			ft_rotate(t_stack *stacks, char rec, char instruction);
void			ft_reverse_rotate(t_stack *stacks, char rec, char instruction);

/*
**		Cheating:)
*/

void			ft_check_buffer(t_stack *s);

/*
**		Swap_or_Push tools
*/

void			ft_list_to_array(t_dlist *stack, int *array, int size);
t_byte			ft_is_sort(t_stack *stacks);
int				ft_find_a_median(t_dlist *stack, int size);
int				ft_max(t_dlist *s, int len);
int				ft_less_than_median(int med, t_dlist *s, int size, char flag);

/*
**		Universal_functions
*/

int				ft_allfree(t_stack *stacks);
void			ft_flag_searcher(t_stack *stacks, int argc, char **argv);
void			ft_represent(t_stack *stacks, int iter);

#endif
