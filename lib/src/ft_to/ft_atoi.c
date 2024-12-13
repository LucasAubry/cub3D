/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:49:25 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/13 20:22:40 by laubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_atoi_256(const char *str)
{
	int	tab[4];

	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 0;
	while (str[tab[0]] == ' ' || ('\t' <= str[tab[0]] && str[tab[0]] <= '\r'))
		tab[0]++;
	if (str[tab[0]] == '-' || str[tab[0]] == '+')
	{
		if (str[tab[0]] == '-')
			tab[1] = -tab[1];
		tab[0]++;
	}
	tab[3] = tab[0];
	while (str[tab[0]] >= '0' && str[tab[0]] <= '9')
	{
		tab[2] = tab[2] * 10 + (str[tab[0]] - '0');
		tab[0]++;
	}
	if ((tab[0] - tab[3]) > 3)
		return (256);
	return (tab[2] * tab[1]);
}
