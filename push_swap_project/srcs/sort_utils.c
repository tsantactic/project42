/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:27:32 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/06 22:41:30 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	test_if_sorted(int *arr, int len)
{
	int	i;
	int	is_sorted;

	is_sorted = 1;
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			is_sorted = 0;
			break ;
		}
		i++;
	}
	return (is_sorted);
}

void	sort_with_median(t_stack a)
{
	int	get_median;
	int	min_index;

	get_median = a.size / 2;
	min_index = search_min(a.arr, a.size);
	while (min_index != 0)
	{
		if (min_index <= get_median)
		{
			rotate(a.arr, a.size, 1);
		}
		else
		{
			reverse_rotate(a.arr, a.size, 1);
		}
		min_index = search_min(a.arr, a.size);
	}
}
