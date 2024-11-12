/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:38:06 by ariling           #+#    #+#             */
/*   Updated: 2024/09/06 12:27:09 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_unsigned(va_list args)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(args, unsigned int);
	str = ft_itoa_unsigned(n);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
