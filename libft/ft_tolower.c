/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:18:38 by ariling           #+#    #+#             */
/*   Updated: 2024/05/30 20:33:32 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

// int main(void)
// {
// 	int c = 'A';
// 	int result = ft_tolower(c);
// 	char result_buildin = tolower(c);
// 	printf("%c buildin : %c\n", result, result_buildin);
// }
