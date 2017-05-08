/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_usages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:19:15 by idemchen          #+#    #+#             */
/*   Updated: 2017/05/06 22:17:09 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned	ft_check_integer(char *str)
{
	unsigned	counter;

	counter = 0;
	while (SPACED(*str) || TABBED(*str)
		|| DIGIT(*str))
		(++counter) && (str++);
	if (counter == __builtin_strlen(str))
		return (1);
	exit(write(2, "\033[0;31mNon-digit character\033[0m\n", 31));
}

int				ft_multiatoi(char **str)
{
	char	sign;
	long	nbr;

	sign = 0;
	while (SPACED(**str) || TABBED(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
		sign = (*(*str)++ == '-') ? 1 : 0;
	nbr = 0;
	while (DIGIT(**str))
		(nbr = nbr * 10 + *(*str)++ - 48);
	if (**str && !(SPACED(**str) || TABBED(**str)))
		exit(write(2, "\033[0;31mNon-digit character\033[0m\n", 31));
	nbr = sign ? -nbr : nbr;
	if (nbr > 2147483647 || nbr < -2147483648)
		exit(write(2, "\033[0;31mInt Overflow\033[0m\n", 24));
	return ((int)nbr);
}

int				ps_ft_atoi(char *str)
{
	char	sign;
	long	nbr;

	sign = 1;
	while (SPACED(*str) || TABBED(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	nbr = 0;
	while (*str >= 48 && *str <= 57)
		(nbr = nbr * 10 + *str++ - 48);
	if (!ft_check_integer(str)
		|| !(sign * nbr <= 2147483647 && sign * nbr >= -2147483648))
		exit(write(2, "\033[0;31mInt Overflow\033[0m\n", 24));
	return (sign * nbr);
}
