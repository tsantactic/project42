/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:20:07 by sandriam          #+#    #+#             */
/*   Updated: 2024/03/09 13:15:07 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char )c)
		{
			last_occurrence = (char *)s;
		}
		s++;
	}
	if (*s == (char )c)
	{
		last_occurrence = (char *)s;
	}
	return (last_occurrence);
}
