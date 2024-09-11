/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_radix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:05:27 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/05 16:59:51 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_stack(char *str, t_stack *s)
{
	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->size_a <= 0)
			return ;
		ft_memmove(s->a + 1, s->a, sizeof(int) * s->size_a);
		s->a[0] = s->b[0];
		s->size_b--;
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->size_b);
		s->size_a++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (s->size_a <= 0)
			return ;
		ft_memmove(s->b + 1, s->b, sizeof(int) * s->size_b);
		s->b[0] = s->a[0];
		s->size_a--;
		ft_memmove(s->a, s->a + 1, sizeof(int) * s->size_a);
		s->size_b++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate_stack(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "normal", 7) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "revs", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
