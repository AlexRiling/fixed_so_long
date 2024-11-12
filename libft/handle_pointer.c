/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:38:24 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:29:42 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_pointer(va_list args)
{
	void	*ptr;
	char	*str;
	int		len;

	ptr = va_arg(args, void *);
	str = ft_itoa_ptr((unsigned long)ptr);
	len = write(1, "0x", 2) + write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
