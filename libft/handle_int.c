/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:38:38 by ariling           #+#    #+#             */
/*   Updated: 2024/11/05 22:29:24 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_int(va_list args)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(args, int);
	str = ft_itoa(n);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
