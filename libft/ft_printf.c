/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:09:12 by ariling           #+#    #+#             */
/*   Updated: 2024/06/29 18:38:01 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_format(va_list args, char format)
{
	if (format == 'c')
		return (handle_char(args));
	else if (format == 's')
		return (handle_string(args));
	else if (format == 'd' || format == 'i')
		return (handle_int(args));
	else if (format == 'u')
		return (handle_unsigned(args));
	else if (format == 'x' || format == 'X')
		return (handle_hex(args, format));
	else if (format == 'p')
		return (handle_pointer(args));
	else if (format == '%')
		return (handle_percent());
	return (0);
}

int	ft_vprintf(const char *format, va_list args)
{
	int	printed;

	printed = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			printed += handle_format(args, *(++format));
		}
		else
		{
			printed += ft_putchar_fd(*format, 1);
		}
		format++;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	va_start(args, format);
	printed = ft_vprintf(format, args);
	va_end(args);
	return (printed);
}
