/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:06:45 by sandriam          #+#    #+#             */
/*   Updated: 2024/03/08 16:57:09 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	str_final;

	i = 0;
	signe = 1;
	str_final = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else
		if (nptr[i] == '+')
			i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		str_final = str_final * 10 + (nptr[i] - '0');
		i++;
	}
	str_final *= signe;
	return (str_final);
}
