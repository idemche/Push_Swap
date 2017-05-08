/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:28:38 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:31:21 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_substitute(char *str, char *s, int l)
{
	while (*s)
		*(str++) = *(s++);
	str--;
	while (*(++str + l))
		*str = *(str + l);
	while (--l)
		*(str++) = 0;
	return (1);
}

void		ft_check_buffer(t_stack *s)
{
	char	*res;

	while ((res = __builtin_strstr(s->buffer, "\npa\npb\n")))
		ft_substitute(res, "\n", 6) && (s->iterator -= 6);
	while ((res = __builtin_strstr(s->buffer, "\npb\npa\n")))
		ft_substitute(res, "\n", 6) && (s->iterator -= 6);
	while ((res = __builtin_strstr(s->buffer, "\nrra\nra\n")))
		ft_substitute(res, "\n", 7) && (s->iterator -= 7);
	while ((res = __builtin_strstr(s->buffer, "sa\nsb")))
		ft_substitute(res, "ss", 3) && (s->iterator -= 3);
	while ((res = __builtin_strstr(s->buffer, "sa\nsb")))
		ft_substitute(res, "ss", 3) && (s->iterator -= 3);
	while ((res = __builtin_strstr(s->buffer, "\nrrb\nrb\n")))
		ft_substitute(res, "\n", 7) && (s->iterator -= 7);
	while ((res = __builtin_strstr(s->buffer, "\nra\nrra\n")))
		ft_substitute(res, "\n", 7) && (s->iterator -= 7);
	while ((res = __builtin_strstr(s->buffer, "\nrb\nrrb\n")))
		ft_substitute(res, "\n", 7) && (s->iterator -= 7);
	while ((res = __builtin_strstr(s->buffer, "rra\nrrb")))
		ft_substitute(res, "rrr", 4) && (s->iterator -= 4);
	while ((res = __builtin_strstr(s->buffer, "rrb\nrra")))
		ft_substitute(res, "rrr", 4) && (s->iterator -= 4);
}
