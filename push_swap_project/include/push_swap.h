/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:51:43 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 21:19:52 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/include/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	size;
	int	capacity;
}		t_stack;

void	ft_print_error(void);
void	sort(char *argv);
void	ft_free(char **str);
void	swap(int *arr, int size);
void	push_to_dest(t_stack dest, int value);
void	remove_from_src(t_stack src);
void	push(t_stack src, t_stack dest, int is_to_a);
void	rotate(int *arr, int size, int is_to_a);
void	reverse_rotate(int *arr, int size, int is_to_a);
void	sort_three(int *arr);
void	sort_more(t_stack a, t_stack b, char *str);
void	sort_with_median(t_stack a);
void	free_and_exit(t_stack *s, char *msg);
void	copy_numbers(t_stack *s, t_stack a);
void	push_stack(char *str, t_stack *s);
void	rotate_stack(int *array, int size, char *direction, char *list);
void	create_index(int *arr, int len);
int		exit_if_sorted(t_stack *s, t_stack a);
int		is_array_sorted(t_stack *s);
int		radix_sort(t_stack a);
int		ft_alpha(int c);
int		*ft_parse_input(char *argv, int *len);
int		ft_withqm(char *str);
int		test_if_sorted(int *arr, int len);
int		search_min(int *arr, int len);
int		search_max(int *arr, int len);
int		ft_isspace(char c);
int		search_place(int size, int index, int *arr, int i);
void	exit_if_sort(t_stack a, t_stack b, char *str);

#endif
