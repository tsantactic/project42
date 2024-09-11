/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:53:58 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 21:17:28 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_copy(int *arr, char **args)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	j = 0;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_print_error();
		arr[j++] = (int)tmp;
		i++;
	}
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_parse_input(char *argv, int *len)
{
	char	**args;
	int		*arr;
	int		i;

	i = 0;
	args = ft_split(argv, ' ');
	if (!args)
		ft_print_error();
	while (args[i])
		i++;
	*len = i;
	arr = malloc(i * sizeof(int));
	if (!arr)
		ft_print_error();
	ft_copy(arr, args);
	ft_free(args);
	if (has_duplicates(arr, i))
	{
		free(arr);
		return (0);
	}
	return (arr);
}

static void	ft_sort(t_stack a, t_stack b, char *str)
{
	if (a.size == 2 && a.arr[0] > a.arr[1])
		swap(a.arr, a.size);
	else if (a.size == 3)
		sort_three(a.arr);
	else if (a.size >= 4 && a.size <= 20)
		sort_more(a, b, str);
	else if (a.size > 20)
	{
		if (radix_sort(a) == 0)
		{
			free(b.arr);
			free(str);
			exit(0);
		}
		else
		{
			free(b.arr);
			free(str);
			exit(1);
		}
	}
}

void	sort(char *str)
{
	t_stack	a;
	t_stack	b;

	b.capacity = 100;
	a.capacity = 100;
	a.arr = ft_parse_input(str, &a.size);
	b.arr = malloc(b.capacity * sizeof(int));
	if (!b.arr || !a.arr)
	{
		if (b.arr)
			free(b.arr);
		else if (a.arr)
			free(a.arr);
		free(str);
		ft_print_error();
	}
	b.size = 0;
	ft_sort(a, b, str);
	free(a.arr);
	free(b.arr);
}
