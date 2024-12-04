/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_handle_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:19 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/04 22:26:24 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_e_handle_i(va_list args)
{
	int		number;
	int		len;

	number = va_arg(args, int);
	ft_putnbr_fd(number, 2);
	len = ft_number_len(number);
	return (len);
}
