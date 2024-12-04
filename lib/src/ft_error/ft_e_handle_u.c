/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_handle_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:33 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/04 22:26:37 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unbrlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

int	ft_e_handle_u(va_list args)
{
	unsigned int		number;
	int					len;

	number = va_arg(args, unsigned int);
	ft_putunbr_fd(number, 2);
	len = ft_unbrlen(number);
	return (len);
}
