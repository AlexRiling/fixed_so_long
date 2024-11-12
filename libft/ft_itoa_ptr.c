/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:22:37 by ariling           #+#    #+#             */
/*   Updated: 2024/06/29 11:18:50 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ptr(unsigned long ptr)
{
	char			*str;
	unsigned long	tmp;
	int				len;

	tmp = ptr;
	len = 2;
	while (tmp != 0)
	{
		tmp /= 16;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 2)
	{
		str[len] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
