/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:11 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/09 07:08:41 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_result(const char *format, va_list ap)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (format = '\0')
	{
		write(1, format[i], 1);
		if (format[i] = '%')
		{
			count++;
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	result;

	if (!format)
		return (0);
	va_start(ap, arg_1);
	result = print_result(format, ap);
	va_end(ap);
	return (result);
}
