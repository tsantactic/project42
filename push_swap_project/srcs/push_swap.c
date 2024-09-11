/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:51:51 by sandriam          #+#    #+#             */
/*   Updated: 2024/09/07 14:24:23 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	space_manage(int i, char *new_s)
{
	if (i > 0)
	{
		new_s[i] = ' ';
		i++;
	}
	return (i);
}

char	*ft_strjoin_p(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_s[i] = s1[i];
		i++;
	}
	i = space_manage(i, new_s);
	j = 0;
	while (s2[j] != '\0')
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	return (new_s);
}

void	call_fonction_sort(char *result, int arg, char **argv)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < arg)
	{
		temp = ft_strjoin_p(result, argv[i]);
		if (!temp)
		{
			free(result);
			ft_print_error();
		}
		free(result);
		result = temp;
		i++;
	}
	ft_withqm(result);
	sort(result);
	free(result);
}

void	check_space(int arg, char **argv)
{
	int	i;
	int	j;
	int	len;
	int	is_spaces;

	i = 0;
	while (++i < arg)
	{
		len = ft_strlen(argv[i]);
		is_spaces = 1;
		j = -1;
		while (++j < len)
		{
			if (!ft_isspace(argv[i][j]))
			{
				is_spaces = 0;
				break ;
			}
		}
		if (is_spaces)
			ft_print_error();
	}
}

int	main(int arg, char **argv)
{
	char	*result;

	if (arg > 1)
	{
		check_space(arg, argv);
		result = (char *)malloc(1 * sizeof(char));
		if (!result)
			ft_print_error();
		result[0] = '\0';
		call_fonction_sort(result, arg, argv);
	}
	return (0);
}
