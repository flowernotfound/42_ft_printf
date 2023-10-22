/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:38:38 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/22 22:46:05 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_hex(unsigned long long p)
{
	char	*hex;
	char	*base;
	char	*result;
	int		length;

	base = "0123456789abcdef";
	length = 1;
	hex = p;
	while (hex /= 16)
		length++;
	if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	result[length] = '\0';
	while (length--)
	{
		result[length] = base[p % 16];
		p /= 16;
	}
	return (result);
}

static int	print_p_left(void *p, t_flags flags, char padding)
{
	int		count;
	char	*address;

	address = convert_hex((unsigned long long)p);
	if (!address)
		return (-1);
	count = ft_strlen(address) + 2;
	write(1, "0x", 2);
	write(1, address, count - 2);
	while (count < flags.width)
	{
		write(1, &padding, 1);
		count++;
	}
	free(address);
	return (count);
}

static int	print_p_right(void *p, t_flags flags, char padding)
{
	int		count;
	int		padding_length;
	char	*address;

	address = convert_hex((unsigned long long)p);
	if (!address)
		return (-1);
	count = ft_strlen(address) + 2;
	padding_length = flags.width - count;
	while (padding_length > 0)
	{
		write(1, &padding, 1);
		padding_length--;
	}
	write(1, "0x", 2);
	write(1, address, count - 2);
	free(address);
	if (flags.width > count)
		return (flags.width);
	return (count);
}

int	print_p(void *p, t_flags flags)
{
	char	padding;

	if (flags.zero_padding && !flags.left_justify)
		padding = '0';
	else
		padding = ' ';
	if (flags.left_justify)
		return (print_p_left(p, flags, padding));
	else
		return (print_p_right(p, flags, padding));
}
