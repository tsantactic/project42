/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:41:01 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/24 17:42:16 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	ft_is_digit(char s)
{
	if (s >= '0' && s <= '9')
	{
		return (0);
	}
	return (1);
}

static int	check_all_v(int h, char argv, char argv_p)
{
	if (argv == '.')
	{
		if (h || argv_p == '\0')
			return (1);
		h = 1;
	}
	else if (ft_is_digit(argv) == 1)
		return (1);
	return (0);
}

int	check_values(char **argv)
{
	int	i;
	int	j;
	int	has_point;

	i = 2;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		if (argv[i][j] == '.')
			return (1);
		has_point = 0;
		while (argv[i][j])
		{
			if (check_all_v(has_point, argv[i][j], argv[i][j + 1]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
