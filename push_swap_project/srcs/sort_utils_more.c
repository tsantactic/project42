/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:52:55 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 21:20:14 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	search_max(int *arr, int len)
{
	int	i;
	int	max_index;

	max_index = 0;
	i = 0;
	while (i < len)
	{
		if (arr[i] > arr[max_index])
		{
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	search_min(int *arr, int len)
{
	int	i;
	int	min_index;

	min_index = 0;
	i = 0;
	while (i < len)
	{
		if (arr[i] < arr[min_index])
		{
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	search_place(int size, int index, int *arr, int direction)
{
	int	median;

	median = size / 2;
	if (index <= median)
	{
		rotate(arr, size, direction);
		index--;
	}
	else
	{
		reverse_rotate(arr, size, direction);
		index -= size;
	}
	return (index);
}
