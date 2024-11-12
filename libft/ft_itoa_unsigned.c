/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:22:33 by ariling           #+#    #+#             */
/*   Updated: 2024/06/29 11:18:45 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_unsigned_str(char *str, unsigned int n, int len)
{
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	else
	{
		while (len--)
		{
			str[len] = (n % 10) + '0';
			n /= 10;
		}
	}
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = get_unsigned_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	fill_unsigned_str(str, n, len);
	return (str);
}
