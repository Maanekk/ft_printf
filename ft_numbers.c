/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:19:55 by mmankows          #+#    #+#             */
/*   Updated: 2026/10/13 16:19:55 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned(unsigned long long number, const char *base,
		unsigned int base_size)
{
	int	count;
	int	result;

	count = 0;
	if (number >= base_size)
		count = put_unsigned(number / base_size, base, base_size);
	if (count < 0)
		return (-1);
	result = put_char(base[number % base_size]);
	if (result < 0)
		return (-1);
	return (count + result);
}

int	put_signed(int number)
{
	long long	value;
	int			count;
	int			result;

	value = number;
	count = 0;
	if (value < 0)
	{
		result = put_char('-');
		if (result < 0)
			return (-1);
		count += result;
		value = -value;
	}
	if (value >= 10)
	{
		result = put_signed((int)(value / 10));
		if (result < 0)
			return (-1);
		count += result;
	}
	result = put_char((char)('0' + value % 10));
	if (result < 0)
		return (-1);
	return (count + result);
}
