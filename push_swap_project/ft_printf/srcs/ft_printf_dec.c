/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:17:22 by sandriam          #+#    #+#             */
/*   Updated: 2024/06/03 15:23:31 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	rest_of_nbr(int nbr, int res)
{
	int		i;
	char	buffer[12];

	i = 0;
	while (nbr)
	{
		buffer[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		res++;
	}
	return (res);
}

int	ft_printf_dec(int nbr)
{
	int		res;

	res = 0;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nbr = 147483648;
		res++;
		res++;
	}
	else if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		res++;
	}
	if (nbr == 0)
		return (write(1, "0", 1));
	res = rest_of_nbr(nbr, res);
	return (res);
}
