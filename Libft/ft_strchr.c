/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:24:30 by sandriam          #+#    #+#             */
/*   Updated: 2024/03/09 13:18:44 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char )c)
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if ((char )c == *s)
		return ((char *)s);
	else
		return (0);
}
