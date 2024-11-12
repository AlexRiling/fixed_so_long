/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:23:40 by ariling           #+#    #+#             */
/*   Updated: 2024/05/30 21:51:51 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
// 	int result = ft_isprint(c);
// 	int result_buildin = isprint(c);
// 	printf("%d build-in function.\n\n", result_buildin);
// 	printf("%d my function.\n\n", result);
// }
