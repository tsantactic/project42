/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:49:47 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/04 18:08:49 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_dest(t_stack dest, int value)
{
	int	i;

	if (dest.size >= dest.capacity)
	{
		return ;
	}
	i = dest.size;
	while (i > 0)
	{
		dest.arr[i] = dest.arr[i - 1];
		i--;
	}
	dest.arr[0] = value;
	dest.size++;
}

void	remove_from_src(t_stack src)
{
	int	i;

	if (src.size < 1)
	{
		return ;
	}
	i = 0;
	while (i < src.size - 1)
	{
		src.arr[i] = src.arr[i + 1];
		i++;
	}
	src.size--;
}
