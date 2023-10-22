/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:27:09 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/22 17:19:30 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_left(char *s, t_flags flags, char padding)
{
	int	count;
	int	length;

	length = ft_strlen(s);
	if (flags.precision >= 0 && flags.precision < length)
		length = flags.precision;
	write(1, s, length);
	count = length;
	while (count < flags.width)
	{
		write(1, &padding, 1);
		count++;
	}
	return (count);
}

static int	print_str_right(char *s, t_flags flags, char padding)
{
	int	count;
	int	s_length;
	int	padding_length;

	s_length = ft_strlen(s);
	if (flags.precision >= 0 && flags.precision < s_length)
		s_length = flags.precision;
	if (flags.width > s_length)
		padding_length = flags.width - s_length;
	else
		padding_length = 0;
	count = 0;
	while (count < padding_length)
	{
		write(1, &padding, 1);
		count++;
	}
	write(1, s, s_length);
	return (count + s_length);
}

int	print_str(char *s, t_flags flags)
{
	char	padding;

	if (!s)
		s = "(null)";
	if (flags.zero_padding && !flags.left_justify)
		padding = '0';
	else
		padding = ' ';
	if (flags.left_justify)
		return (print_str_left(s, flags, padding));
	else
		return (print_str_right(s, flags, padding));
}
