/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:56:43 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/19 00:56:38 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_flags flags)
{
	int	count;
	char	padding;

	if (flags.zero_padding && !flags.left_justify)
		padding = '0';
	else
		padding = ' ';
	if (flags.left_justify)
	{
		write(1, &c, 1);
		count++;
		while (count < flags.width)
		{
			write(1, &padding, 1);
			count++;
		}
	}
	else
	{

	}
}
