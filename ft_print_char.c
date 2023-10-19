/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:56:43 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/19 12:45:10 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_left(int c, t_flags flags, char padding)
{
	int	count;

	write(1, &c, 1);
	count = 1;
	while (count < flags.width)
	{
		write(1, &padding, 1);
		count++;
	}
	return (count);
}

static int	print_right(int c, t_flags flags, char padding)
{
	int	count;

	count = 0;
	while (count < flags.width - 1)
	{
		write(1, &padding, 1);
		count++;
	}
	write(1, &c, 1);
	count++;
	return (count);
}

int	print_char(int c, t_flags flags)
{
	char	padding;

	if (flags.zero_padding && !flags.left_justify)
		padding = '0';
	else
		padding = ' ';
	if (flags.left_justify)
		return (print_left(c, flags, padding));
	else
		return (print_right(c, flags, padding));
}
