/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:38:38 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/22 17:45:11 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_hex(unsigned long long p)
{
}

int	print_p(void *p, t_flags flags)
{
	int		count;
	char	*address;

	address = convert_hex((unsigned long long)p);
	if (!address)
		return (-1);
	count = ft_strlen(address) + 2;
	write(1, "0x", 2);
	write(1, address, count - 2);
	free(address);
	return (count);
}
