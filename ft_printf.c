/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:11 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/06 04:58:40 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_result()
{
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	result;

	va_start(ap, arg_1);
	result = print_result();
	va_end(ap);
	return (result);
}
