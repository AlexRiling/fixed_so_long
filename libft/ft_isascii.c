/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:13:31 by ariling           #+#    #+#             */
/*   Updated: 2024/05/30 21:48:06 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main(void)
// {
// 	int c = 'a';
// 	int result = ft_isascii(c);
// 	int result_buildin = isascii(c);
// 	printf("%d build-in function.\n\n", result_buildin);
// 	printf("%d my function.\n\n", result);
// }
