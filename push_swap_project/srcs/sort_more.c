/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:15 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/08 14:50:36 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_index(int *arr, int len)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(len * sizeof * new_a);
	if (!new_a)
	{
		free(arr);
		ft_print_error();
	}
	i = -1;
	while (++i < len)
	{
		k = 1;
		j = -1;
		while (++j < len)
			if (arr[i] > arr[j])
				k++;
		new_a[i] = k;
	}
	i = len;
	while (i--)
		arr[i] = new_a[i];
	free(new_a);
}

void	exit_if_sort(t_stack a, t_stack b, char *str)
{
	if (test_if_sorted(a.arr, a.size) == 1)
	{
		free(str);
		free(a.arr);
		free(b.arr);
		exit(1);
	}
}

void	sort_more(t_stack a, t_stack b, char *str)
{
	int	max_index;

	exit_if_sort(a, b, str);
	create_index(a.arr, a.size);
	while (a.size > 3)
	{
		sort_with_median(a);
		push(a, b, 0);
		a.size--;
		b.size++;
	}
	sort_three(a.arr);
	max_index = search_max(b.arr, b.size);
	while (b.size >= 1)
	{
		while (max_index > 0)
			max_index = search_place(b.size, max_index, b.arr, 0);
		push(b, a, 1);
		a.size++;
		b.size--;
		max_index = search_max(b.arr, b.size);
	}
}
