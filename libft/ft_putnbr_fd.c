/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariling <ariling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:16 by ariling           #+#    #+#             */
/*   Updated: 2024/05/30 23:21:55 by ariling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursive_fd(int n, int fd)
{
	char	c;

	if (n > 9 || n < -9)
		ft_putnbr_recursive_fd(n / 10, fd);
	if (n < 0)
		c = '0' - (n % 10);
	else
		c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_putnbr_recursive_fd(n, fd);
}
