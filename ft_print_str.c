/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:27:09 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/21 19:06:21 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_left(char *s, t_flags flags, char padding)
{
}

static int	print_str_right(char *s, t_flags flags, char padding)
{
}

int	print_str(char *s, t_flags flags)
{
	char	padding;

	if (!s)
		s = "(null)";
	if (flgas.zero_padding && !flags.left_justify)
		padding = '0';
	else
		padding = ' ';
	if (flags.left_justify)
		return (print_str_left(s, flags, padding));
	else
		return (print_str_right(s, flgas, padding));
}
