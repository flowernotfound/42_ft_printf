/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:36:59 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/17 16:13:33 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef struct	s_flags
{
	int	left_justfy;
	int	zero_padding;
	int	precision;
	int	hash;
	int	plus;
	int	space;
}	t_flags;

#endif
