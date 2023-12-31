/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:11 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/19 12:32:19 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char *format, int *i, t_flags *flags)
{
	while (1)
	{
		if (format[*i] == '-')
			flags->left_justify = 1;
		else if (format[*i] == '.')
			parse_precision(format, i, flags);
		else if (format[*i] == '0' && flags->precision == -1)
			flags->zero_padding = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (is_digit(format[*i]))
			parse_width(format, i, flags);
		else
			break ;
		(*i)++;
	}
}

int	print_arg(char type, va_list ap, t_flags flags)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(ap, int), flags);
	else if (type == 's')
		count += print_str(va_arg(ap, char *), flags);
	else if (type == 'p')
		count += print_p(va_arg(ap, void *), flags);
	else if (type == 'd')
		count += print_int(va_arg(ap, int), flags);
	else if (type == 'i')
		count += print_int(va_arg(ap, int), flags);
	else if (type == 'u')
		count += print_unsigned(va_arg(ap, unsigned int), flags);
	else if (type == 'x')
		count += print_hex(va_arg(ap, unsigned int), 0, flags);
	else if (type == 'X')
		count += print_hex(va_arg(ap, unsigned int), 1, flags);
	else if (type == '%')
		count += print_percent(flags);
	return (count);
}

int	print_result(const char *format, va_list ap)
{
	t_flags	flags;
	int		count;
	int		i;

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
	int		result;

	if (!format)
		return (0);
	va_start(ap, format);
	result = print_result(format, ap);
	va_end(ap);
	return (result);
}
