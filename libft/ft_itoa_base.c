/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:22:40 by ariling           #+#    #+#             */
/*   Updated: 2024/06/29 11:18:55 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(unsigned int value, unsigned int base_len)
{
	int	len;

	len = 0;
	if (value == 0)
		len = 1;
	else
	{
		while (value != 0)
		{
			value /= base_len;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa_base(unsigned int value, const char *base)
{
	char			*str;
	unsigned int	base_len;
	int				len;

	base_len = ft_strlen(base);
	len = get_len(value, base_len);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (value == 0)
		str[0] = base[0];
	else
	{
		while (len--)
		{
			str[len] = base[value % base_len];
			value /= base_len;
		}
	}
	return (str);
}
