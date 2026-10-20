/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:20:05 by mmankows          #+#    #+#             */
/*   Updated: 2026/10/13 16:20:05 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	put_char(char character)
{
	return (write(1, &character, 1));
}

int	put_string(const char *string)
{
	int	length;

	if (!string)
		string = "(null)";
	length = 0;
	while (string[length])
		length++;
	if (write(1, string, length) < 0)
		return (-1);
	return (length);
}

int	put_pointer(void *pointer)
{
	int	count;

	if (!pointer)
		return (put_string("(nil)"));
	count = put_string("0x");
	if (count < 0)
		return (-1);
	return (count + put_unsigned((unsigned long long)pointer,
			"0123456789abcdef", 16));
}
