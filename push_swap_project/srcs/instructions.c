/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:01:36 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 10:14:20 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack src, t_stack dest, int is_to_a)
{
	t_stack	src_copy;
	t_stack	dest_copy;

	src_copy = src;
	dest_copy = dest;
	push_to_dest(dest_copy, src_copy.arr[0]);
	remove_from_src(src_copy);
	if (is_to_a)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	swap(int *arr, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	ft_printf("sa\n");
}

void	rotate(int *arr, int size, int is_to_a)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = arr[0];
	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = temp;
	if (is_to_a)
		ft_printf("ra\n");
	else if (is_to_a == 0)
		ft_printf("rb\n");
}

void	reverse_rotate(int *arr, int size, int is_to_a)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = arr[size - 1];
	i = size - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
	if (is_to_a)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
