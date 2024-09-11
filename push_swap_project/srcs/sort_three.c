/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:23:46 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/02 11:26:12 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(int *arr)
{
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		swap(arr, 3);
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		swap(arr, 3);
		reverse_rotate(arr, 3, 1);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		rotate(arr, 3, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		swap(arr, 3);
		rotate(arr, 3, 1);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		reverse_rotate(arr, 3, 1);
}
