/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:46:02 by sandriam          #+#    #+#             */
/*   Updated: 2024/06/03 16:11:29 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_put_fd((num + '0'), 1);
		else
			ft_put_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	print_res;

	print_res = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		print_res += write(1, "0x", 2);
		ft_put_ptr(ptr);
		print_res += ft_ptr_len(ptr);
	}
	return (print_res);
}
