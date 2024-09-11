/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:52:36 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 13:26:42 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_and_exit(t_stack *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s->a != NULL)
		free(s->a);
	if (s->b != NULL)
		free(s->b);
	if (s != NULL)
		free(s);
	exit(1);
}

void	copy_numbers(t_stack *s, t_stack a)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (i < a.size)
	{
		s->a[z++] = a.arr[i++];
	}
}

int	is_array_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size_a - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	exit_if_sorted(t_stack *s, t_stack a)
{
	if (is_array_sorted(s))
	{
		free(a.arr);
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s != NULL)
			free(s);
		return (1);
	}
	return (0);
}
