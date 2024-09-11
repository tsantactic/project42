/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_withqm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:32:02 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 14:24:20 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_test_digit(char *str)
{
	int	i;
	int	is_sign;

	is_sign = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		is_sign = 1;
		i++;
	}
	if (!str[i] && is_sign == 1)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_double(int index, char **arg)
{
	int	x;

	x = 0;
	while (arg[x])
	{
		if (x != index && ft_strcmp(arg[index], arg[x]) == 0)
			return (1);
		x++;
	}
	return (0);
}

static void	check_arg(int i, char **arg, char *str)
{
	long	tmp;

	if (ft_test_digit(arg[i]) == 1)
	{
		ft_free(arg);
		free(str);
		ft_print_error();
	}
	tmp = ft_atoi(arg[i]);
	if (tmp < -2147483648 || tmp > 2147483647)
	{
		ft_free(arg);
		free(str);
		ft_print_error();
	}
	if (ft_double(i, arg) == 1)
	{
		ft_free(arg);
		free(str);
		ft_print_error();
	}
}

int	ft_withqm(char *str)
{
	int		i;
	char	**arg;

	i = 0;
	arg = ft_split(str, ' ');
	if (!arg)
	{
		free(str);
		ft_print_error();
	}
	while (arg[i])
	{
		check_arg(i, arg, str);
		i++;
	}
	ft_free(arg);
	return (0);
}
