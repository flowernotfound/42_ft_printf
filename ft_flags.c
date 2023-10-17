/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:39:50 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/17 16:40:31 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	initialize_flags(void)
{
	t_flags flags;

	flags.left_justfy = 0;
	flags.zero_padding = 0;
	flags.precision = -1;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	return (flags);
}
