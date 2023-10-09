/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:11 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/09 22:40:09 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char *format, int *i, t_flags *flags)
{
	while (format[*i] != '\0')
	{
		if (format[*i] == '-')
			flags->left_justfy = 1;
		else if (format[*i] == '0')
			flags->zero_padding = 1;
		else if (format[*i] == '.')
			flags->precision = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else
			break;
		(*i)++;
	}
}

int	print_arg(char type, va_list ap, t_flags flags)
{

}

int	print_result(const char *format, va_list ap)
{
	t_flags	flags;
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		flags = initialize_flags();
		if (format[i] == '%')
		{
			i++;
			parse_flags(format, &i, &flags);
			count += print_arg(format[i], ap, flags);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	result;

	if (!format)
		return (0);
	va_start(ap, format);
	result = print_result(format, ap);
	va_end(ap);
	return (result);
}
