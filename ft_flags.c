/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:39:50 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/18 13:11:00 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	initialize_flags(void)
{
	t_flags	flags;

	flags.left_justfy = 0;
	flags.zero_padding = 0;
	flags.precision = -1;
	flags.hash = 0;
	flags.width = 0;
	flags.plus = 0;
	flags.space = 0;
	return (flags);
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

void	parse_precision(const char *format, int *i, t_flags *flags)
{
	(*i)++;
	if (!is_digit(format[*i]))
		flags->precision = 0;
	else
	{
		flags->precision = 0;
		while (is_digit(format[*i]))
		{
			flags->precision = flags->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
		(*i)--;
	}
}

void	parse_width(const char *format, int *i, t_flags *flags)
{
	flags->width = 0;
	while (is_digit(format[*i]))
	{
		flags->width = flags->width * 10 + (format[*i] - '0');
		(*i)++;
	}
	(*i)--;
}
