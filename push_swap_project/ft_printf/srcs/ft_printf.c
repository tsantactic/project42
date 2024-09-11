/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:34:51 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 14:30:36 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_pts(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_printf_str(va_arg(args, const char *)));
	else if (format == 'x' || format == 'X')
		return (ft_printf_hex(va_arg(args, unsigned int), format));
	else if (format == 'd' || format == 'i')
		return (ft_printf_dec(va_arg(args, int)));
	else if (format == 'u')
		return (ft_printf_unsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_printf_percent());
	else if (format == 'p')
		return (ft_printf_ptr(va_arg(args, unsigned long long)));
	return (0);
}

int	ft_printf(const char *arg, ...)
{
	int		res;
	int		i;
	va_list	args;

	va_start(args, arg);
	i = 0;
	res = 0;
	while (arg[i])
	{
		if (arg[i] != '%')
		{
			res += ft_putchar(arg[i]);
		}
		else
		{
			res += ft_pts(args, arg[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
