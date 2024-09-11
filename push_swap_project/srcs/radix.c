/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:36 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/08 14:53:37 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	creates_index(t_stack *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(s->size_a * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit(s, "Error\n");
	i = -1;
	while (++i < s->size_a)
	{
		k = 0;
		j = -1;
		while (++j < s->size_a)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
	}
	i = s->size_a;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}

static void	radix_sort_stack_b(t_stack *s, int size_b, int bit_size, int j)
{
	while (size_b-- && j <= bit_size && !is_array_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate_stack(s->b, s->size_b, "normal", "b");
		else
			push_stack("pa", s);
	}
	if (is_array_sorted(s))
		while (s->size_b != 0)
			push_stack("pa", s);
}

void	sort_number(t_stack *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->size_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->size_a;
		while (size-- && !is_array_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				push_stack("pb", s);
			else
				rotate_stack(s->a, s->size_a, "normal", "a");
		}
		radix_sort_stack_b(s, s->size_b, bit_size, j + 1);
	}
	while (s->size_b != 0)
		push_stack("pa", s);
}

static void	initialising_stack(t_stack *s, t_stack a)
{
	if (s == NULL)
	{
		free(a.arr);
		exit(1);
	}
	s->size_a = a.size;
	s->size_b = 0;
	s->a = malloc(s->size_a * sizeof * s->a);
	s->b = malloc(s->size_a * sizeof * s->b);
	if (s->b == NULL || s->a == NULL)
	{
		free(a.arr);
		free_and_exit(s, "Error\n");
	}
}

int	radix_sort(t_stack a)
{
	t_stack	*s;

	s = malloc(sizeof * s);
	initialising_stack(s, a);
	copy_numbers(s, a);
	if (exit_if_sorted(s, a) == 1)
		return (1);
	creates_index(s);
	sort_number(s);
	if (s->a != NULL)
		free(s->a);
	if (s->b != NULL)
		free(s->b);
	if (s != NULL)
		free(s);
	free(a.arr);
	return (0);
}
