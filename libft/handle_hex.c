/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:38:32 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:29:16 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_hex(va_list args, char format)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(args, unsigned int);
	if (format == 'x')
		str = ft_itoa_base(n, "0123456789abcdef");
	else
		str = ft_itoa_base(n, "0123456789ABCDEF");
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
