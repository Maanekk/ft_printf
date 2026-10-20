/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmankows <mmankows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:21:24 by mmankows          #+#    #+#             */
/*   Updated: 2026/10/13 16:21:24 by mmankows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...)
	__attribute__((format(printf, 1, 2)));

int	put_char(char character);
int	put_string(const char *string);
int	put_pointer(void *pointer);
int	put_unsigned(unsigned long long number, const char *base,
		unsigned int base_size);
int	put_signed(int number);

#endif