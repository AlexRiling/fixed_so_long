/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:33:21 by ariling           #+#    #+#             */
/*   Updated: 2024/05/30 21:47:58 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A'
			&& c <= 'Z'))
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
// 	int c = 'Y';
// 	int result = ft_isalnum(c);
// 	int result_buildin = isalnum(c);
// 	printf("%d build-in function.\n\n", result_buildin);
// 	printf("%d my function.\n\n", result);
// }
