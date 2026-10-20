/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:22:03 by mmankows          #+#    #+#             */
/*   Updated: 2026/10/20 16:22:03 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_conversion(char conversion, va_list *arguments)
{
	if (conversion == 'c')
		return (put_char(va_arg(*arguments, int)));
	if (conversion == 's')
		return (put_string(va_arg(*arguments, char *)));
	if (conversion == 'p')
		return (put_pointer(va_arg(*arguments, void *)));
	if (conversion == 'd' || conversion == 'i')
		return (put_signed(va_arg(*arguments, int)));
	if (conversion == 'u')
		return (put_unsigned(va_arg(*arguments, unsigned int),
				"0123456789", 10));
	if (conversion == 'x')
		return (put_unsigned(va_arg(*arguments, unsigned int),
				"0123456789abcdef", 16));
	if (conversion == 'X')
		return (put_unsigned(va_arg(*arguments, unsigned int),
				"0123456789ABCDEF", 16));
	if (conversion == '%')
		return (put_char('%'));
	return (0);
}

static int	process_format(const char **format, va_list *arguments)
{
	int	written;

	if (**format == '%' && (*format)[1])
	{
		written = print_conversion((*format)[1], arguments);
		*format += 2;
	}
	else
	{
		written = put_char(**format);
		(*format)++;
	}
	return (written);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;
	int		written;

	if (!format)
		return (-1);
	count = 0;
	va_start(arguments, format);
	while (*format)
	{
		written = process_format(&format, &arguments);
		if (written < 0)
		{
			va_end(arguments);
			return (-1);
		}
		count += written;
	}
	va_end(arguments);
	return (count);
}
